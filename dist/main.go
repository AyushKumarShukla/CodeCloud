package main

import (
	"encoding/json"
	"fmt"
	"log"
	"math/rand"
	"net"
	"sync"
	"time"
)

// MessageType represents different types of messages
type MessageType int

const (
	AppMessage MessageType = iota
	MarkerMessage
	StateMessage
)

// Message represents a message in the distributed system
type Message struct {
	Type     MessageType `json:"type"`
	From     int         `json:"from"`
	To       int         `json:"to"`
	Content  string      `json:"content"`
	Snapshot int         `json:"snapshot"`
}

// ChannelState represents the state of a channel during snapshot
type ChannelState struct {
	From     int       `json:"from"`
	To       int       `json:"to"`
	Messages []Message `json:"messages"`
}

// ProcessState represents the local state of a process
type ProcessState struct {
	ID      int    `json:"id"`
	Balance int    `json:"balance"`
	Counter int    `json:"counter"`
	Time    string `json:"time"`
}

// Snapshot represents a global snapshot
type Snapshot struct {
	ID            int                    `json:"id"`
	ProcessStates map[int]ProcessState   `json:"process_states"`
	ChannelStates map[string]ChannelState `json:"channel_states"`
	Complete      bool                   `json:"complete"`
}

// Process represents a node in the distributed system
type Process struct {
	id           int
	balance      int
	counter      int
	neighbors    []int
	
	// Network connections
	listener     net.Listener
	connections  map[int]net.Conn
	
	// Snapshot state
	snapshots        map[int]*Snapshot
	recordingChannels map[int]map[int]bool // snapshot_id -> from_process -> recording
	snapshotMutex    sync.RWMutex
	
	// Message channels
	incomingMessages chan Message
	outgoingMessages chan Message
	
	// Synchronization
	wg           sync.WaitGroup
	shutdown     chan bool
	
	// State mutex
	stateMutex   sync.RWMutex
}

// NewProcess creates a new process
func NewProcess(id int, port int, neighbors []int) *Process {
	listener, err := net.Listen("tcp", fmt.Sprintf(":%d", port))
	if err != nil {
		log.Fatal(err)
	}
	
	return &Process{
		id:               id,
		balance:          rand.Intn(100) + 50, // Random initial balance
		counter:          0,
		neighbors:        neighbors,
		listener:         listener,
		connections:      make(map[int]net.Conn),
		snapshots:        make(map[int]*Snapshot),
		recordingChannels: make(map[int]map[int]bool),
		incomingMessages: make(chan Message, 100),
		outgoingMessages: make(chan Message, 100),
		shutdown:         make(chan bool),
	}
}

// Start begins the process execution
func (p *Process) Start() {
	log.Printf("Process %d starting on port %d", p.id, p.listener.Addr().(*net.TCPAddr).Port)
	
	// Start accepting connections
	p.wg.Add(1)
	go p.acceptConnections()
	
	// Start message processing
	p.wg.Add(1)
	go p.processMessages()
	
	// Start sending messages
	p.wg.Add(1)
	go p.sendMessages()
	
	// Start application logic (simulate work)
	p.wg.Add(1)
	go p.applicationLogic()
}

// Stop shuts down the process
func (p *Process) Stop() {
	close(p.shutdown)
	p.listener.Close()
	
	for _, conn := range p.connections {
		conn.Close()
	}
	
	p.wg.Wait()
	log.Printf("Process %d stopped", p.id)
}

// Connect establishes connections to neighbor processes
func (p *Process) Connect(ports map[int]int) {
	for _, neighborID := range p.neighbors {
		port := ports[neighborID]
		for {
			conn, err := net.Dial("tcp", fmt.Sprintf("localhost:%d", port))
			if err != nil {
				time.Sleep(100 * time.Millisecond)
				continue
			}
			p.connections[neighborID] = conn
			
			// Start listening for messages from this neighbor
			p.wg.Add(1)
			go p.handleConnection(conn, neighborID)
			break
		}
	}
	log.Printf("Process %d connected to all neighbors", p.id)
}

// acceptConnections accepts incoming connections
func (p *Process) acceptConnections() {
	defer p.wg.Done()
	
	for {
		select {
		case <-p.shutdown:
			return
		default:
			conn, err := p.listener.Accept()
			if err != nil {
				return
			}
			
			// We'll determine the neighbor ID from the first message
			p.wg.Add(1)
			go p.handleConnection(conn, -1)
		}
	}
}

// handleConnection handles messages from a connection
func (p *Process) handleConnection(conn net.Conn, neighborID int) {
	defer p.wg.Done()
	defer conn.Close()
	
	decoder := json.NewDecoder(conn)
	
	for {
		var msg Message
		if err := decoder.Decode(&msg); err != nil {
			return
		}
		
		// If we don't know the neighbor ID, learn it from the message
		if neighborID == -1 {
			neighborID = msg.From
			p.connections[neighborID] = conn
		}
		
		p.incomingMessages <- msg
	}
}

// processMessages processes incoming messages
func (p *Process) processMessages() {
	defer p.wg.Done()
	
	for {
		select {
		case <-p.shutdown:
			return
		case msg := <-p.incomingMessages:
			switch msg.Type {
			case AppMessage:
				p.handleApplicationMessage(msg)
			case MarkerMessage:
				p.handleMarkerMessage(msg)
			case StateMessage:
				p.handleStateMessage(msg)
			}
		}
	}
}

// sendMessages sends outgoing messages
func (p *Process) sendMessages() {
	defer p.wg.Done()
	
	for {
		select {
		case <-p.shutdown:
			return
		case msg := <-p.outgoingMessages:
			p.sendMessage(msg)
		}
	}
}

// sendMessage sends a message to a specific process
func (p *Process) sendMessage(msg Message) {
	conn, exists := p.connections[msg.To]
	if !exists {
		log.Printf("Process %d: No connection to process %d", p.id, msg.To)
		return
	}
	
	encoder := json.NewEncoder(conn)
	if err := encoder.Encode(msg); err != nil {
		log.Printf("Process %d: Error sending message to %d: %v", p.id, msg.To, err)
	}
}

// handleApplicationMessage processes application messages
func (p *Process) handleApplicationMessage(msg Message) {
	p.stateMutex.Lock()
	p.counter++
	
	// Simulate some work (e.g., money transfer)
	if msg.Content == "transfer" {
		p.balance += 10
	}
	p.stateMutex.Unlock()
	
	// Record message if we're recording this channel for any snapshot
	p.snapshotMutex.Lock()
	for snapshotID, recording := range p.recordingChannels {
		if recording[msg.From] {
			snapshot := p.snapshots[snapshotID]
			channelKey := fmt.Sprintf("%d->%d", msg.From, p.id)
			
			if snapshot.ChannelStates == nil {
				snapshot.ChannelStates = make(map[string]ChannelState)
			}
			
			state := snapshot.ChannelStates[channelKey]
			state.From = msg.From
			state.To = p.id
			state.Messages = append(state.Messages, msg)
			snapshot.ChannelStates[channelKey] = state
		}
	}
	p.snapshotMutex.Unlock()
	
	log.Printf("Process %d: Received app message from %d, balance=%d, counter=%d", 
		p.id, msg.From, p.balance, p.counter)
}

// handleMarkerMessage processes marker messages (snapshot initiation)
func (p *Process) handleMarkerMessage(msg Message) {
	p.snapshotMutex.Lock()
	defer p.snapshotMutex.Unlock()
	
	snapshotID := msg.Snapshot
	
	// If this is the first marker for this snapshot
	if _, exists := p.snapshots[snapshotID]; !exists {
		// Record local state
		p.stateMutex.RLock()
		localState := ProcessState{
			ID:      p.id,
			Balance: p.balance,
			Counter: p.counter,
			Time:    time.Now().Format(time.RFC3339),
		}
		p.stateMutex.RUnlock()
		
		// Create snapshot
		snapshot := &Snapshot{
			ID:            snapshotID,
			ProcessStates: make(map[int]ProcessState),
			ChannelStates: make(map[string]ChannelState),
			Complete:      false,
		}
		snapshot.ProcessStates[p.id] = localState
		p.snapshots[snapshotID] = snapshot
		
		// Initialize channel recording state
		p.recordingChannels[snapshotID] = make(map[int]bool)
		for _, neighborID := range p.neighbors {
			p.recordingChannels[snapshotID][neighborID] = true
		}
		
		// Send markers to all neighbors
		for _, neighborID := range p.neighbors {
			marker := Message{
				Type:     MarkerMessage,
				From:     p.id,
				To:       neighborID,
				Snapshot: snapshotID,
			}
			p.outgoingMessages <- marker
		}
		
		log.Printf("Process %d: Started snapshot %d", p.id, snapshotID)
	}
	
	// Stop recording from the sender
	if p.recordingChannels[snapshotID] != nil {
		p.recordingChannels[snapshotID][msg.From] = false
		
		// Check if we're done recording all channels
		allStopped := true
		for _, recording := range p.recordingChannels[snapshotID] {
			if recording {
				allStopped = false
				break
			}
		}
		
		if allStopped {
			log.Printf("Process %d: Completed snapshot %d", p.id, snapshotID)
			p.snapshots[snapshotID].Complete = true
			
			// In a real system, you might send this to a coordinator
			p.printSnapshot(snapshotID)
		}
	}
}

// handleStateMessage processes state messages (if implementing distributed collection)
func (p *Process) handleStateMessage(msg Message) {
	// Implementation for collecting distributed snapshots
	// This would be used if you have a coordinator process
	log.Printf("Process %d: Received state message from %d", p.id, msg.From)
}

// InitiateSnapshot starts a new snapshot
func (p *Process) InitiateSnapshot() {
	snapshotID := int(time.Now().UnixNano() / 1e6) // Use timestamp as ID
	
	marker := Message{
		Type:     MarkerMessage,
		From:     p.id,
		To:       p.id, // Send to self to trigger snapshot
		Snapshot: snapshotID,
	}
	
	p.incomingMessages <- marker
	log.Printf("Process %d: Initiated snapshot %d", p.id, snapshotID)
}

// printSnapshot prints a completed snapshot
func (p *Process) printSnapshot(snapshotID int) {
	p.snapshotMutex.RLock()
	snapshot := p.snapshots[snapshotID]
	p.snapshotMutex.RUnlock()
	
	fmt.Printf("\n=== SNAPSHOT %d (Process %d) ===\n", snapshotID, p.id)
	fmt.Printf("Process State: %+v\n", snapshot.ProcessStates[p.id])
	fmt.Printf("Channel States:\n")
	for channelKey, state := range snapshot.ChannelStates {
		fmt.Printf("  %s: %d messages\n", channelKey, len(state.Messages))
		for _, msg := range state.Messages {
			fmt.Printf("    %+v\n", msg)
		}
	}
	fmt.Printf("Complete: %v\n", snapshot.Complete)
	fmt.Printf("================================\n\n")
}

// applicationLogic simulates application work
func (p *Process) applicationLogic() {
	defer p.wg.Done()
	
	ticker := time.NewTicker(2 * time.Second)
	defer ticker.Stop()
	
	for {
		select {
		case <-p.shutdown:
			return
		case <-ticker.C:
			// Randomly send messages to neighbors
			if len(p.neighbors) > 0 {
				neighborID := p.neighbors[rand.Intn(len(p.neighbors))]
				msg := Message{
					Type:    AppMessage,
					From:    p.id,
					To:      neighborID,
					Content: "transfer",
				}
				p.outgoingMessages <- msg
			}
		}
	}
}

// GetSnapshot returns a snapshot if it exists
func (p *Process) GetSnapshot(snapshotID int) (*Snapshot, bool) {
	p.snapshotMutex.RLock()
	defer p.snapshotMutex.RUnlock()
	
	snapshot, exists := p.snapshots[snapshotID]
	return snapshot, exists
}

// Example usage and test
func main() {
	rand.Seed(time.Now().UnixNano())
	
	// Define network topology: 3 processes in a ring
	processes := make([]*Process, 3)
	ports := map[int]int{0: 9080, 1: 9081, 2: 9082}
	
	// Create processes
	processes[0] = NewProcess(0, 9080, []int{1, 2})
	processes[1] = NewProcess(1, 9081, []int{0, 2})
	processes[2] = NewProcess(2, 9082, []int{0, 1})
	
	// Start all processes
	for _, p := range processes {
		p.Start()
	}
	
	// Wait for startup
	time.Sleep(500 * time.Millisecond)
	
	// Connect processes
	for _, p := range processes {
		p.Connect(ports)
	}
	
	// Wait for connections to establish
	time.Sleep(1 * time.Second)
	
	// Let the system run for a bit
	time.Sleep(5 * time.Second)
	
	// Initiate snapshot from process 0
	processes[0].InitiateSnapshot()
	
	// Wait for snapshot to complete
	time.Sleep(3 * time.Second)
	
	// Let system run a bit more
	time.Sleep(5 * time.Second)
	
	// Initiate another snapshot from process 1
	processes[1].InitiateSnapshot()
	
	// Wait for second snapshot
	time.Sleep(3 * time.Second)
	
	// Shutdown
	for _, p := range processes {
		p.Stop()
	}
}

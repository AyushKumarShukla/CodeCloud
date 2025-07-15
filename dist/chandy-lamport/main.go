package main

import (
	"fmt"
	"math/rand"
	"time"
)

// Message types
type MessageType int

const (
	AppMessage    MessageType = 0  // Regular application message
	MarkerMessage MessageType = 1  // Snapshot marker
)

// A message between processes
type Message struct {
	Type       MessageType
	From       int
	To         int
	Content    string
	SnapshotID int
}

// Process represents a node in the distributed system
type Process struct {
	id       int
	balance  int           // Local state (like money in account)
	neighbors []int         // Connected processes
	messages chan Message  // Incoming messages
	
	// Snapshot state
	snapshots map[int]*Snapshot        // snapshotID -> snapshot
	recording map[int]map[int]bool     // snapshotID -> from_process -> is_recording
}

// Snapshot captures the state at a point in time
type Snapshot struct {
	ID            int
	ProcessState  int                    // This process's balance
	ChannelStates map[string][]Message  // Messages recorded on channels
	Complete      bool
}

// Create a new process
func NewProcess(id int, neighbors []int) *Process {
	return &Process{
		id:        id,
		balance:   rand.Intn(100) + 50, // Random starting balance
		neighbors: neighbors,
		messages:  make(chan Message, 100),
		snapshots: make(map[int]*Snapshot),
		recording: make(map[int]map[int]bool),
	}
}

// Start the process (simplified - no actual networking)
func (p *Process) Start(allProcesses map[int]*Process) {
	fmt.Printf("Process %d starting with balance %d\n", p.id, p.balance)
	
	go func() {
		for msg := range p.messages {
			switch msg.Type {
			case AppMessage:
				p.handleAppMessage(msg)
			case MarkerMessage:
				p.handleMarkerMessage(msg, allProcesses)
			}
		}
	}()
}

// Handle regular application messages
func (p *Process) handleAppMessage(msg Message) {
	// Update local state
	p.balance += 10 // Simulate receiving money
	
	// Record message if we're recording this channel for any snapshot
	for snapshotID, recordingMap := range p.recording {
		if recordingMap[msg.From] { // If recording from this sender
			snapshot := p.snapshots[snapshotID]
			channelKey := fmt.Sprintf("%d->%d", msg.From, p.id)
			
			if snapshot.ChannelStates == nil {
				snapshot.ChannelStates = make(map[string][]Message)
			}
			snapshot.ChannelStates[channelKey] = append(snapshot.ChannelStates[channelKey], msg)
		}
	}
	
	fmt.Printf("Process %d: Received message from %d, new balance: %d\n", 
		p.id, msg.From, p.balance)
}

// Handle snapshot marker messages
func (p *Process) handleMarkerMessage(msg Message, allProcesses map[int]*Process) {
	snapshotID := msg.SnapshotID
	
	// If this is the first marker for this snapshot
	if _, exists := p.snapshots[snapshotID]; !exists {
		fmt.Printf("Process %d: Starting snapshot %d\n", p.id, snapshotID)
		
		// 1. Record my current state
		snapshot := &Snapshot{
			ID:           snapshotID,
			ProcessState: p.balance,
			Complete:     false,
		}
		p.snapshots[snapshotID] = snapshot
		
		// 2. Start recording all incoming channels
		p.recording[snapshotID] = make(map[int]bool)
		for _, neighborID := range p.neighbors {
			p.recording[snapshotID][neighborID] = true
		}
		
		// 3. Send markers to all neighbors
		for _, neighborID := range p.neighbors {
			marker := Message{
				Type:       MarkerMessage,
				From:       p.id,
				To:         neighborID,
				SnapshotID: snapshotID,
			}
			allProcesses[neighborID].messages <- marker
		}
	}
	
	// Stop recording from the sender of this marker
	if p.recording[snapshotID] != nil {
		p.recording[snapshotID][msg.From] = false
		
		// Check if we're done recording all channels
		allStopped := true
		for _, isRecording := range p.recording[snapshotID] {
			if isRecording {
				allStopped = false
				break
			}
		}
		
		if allStopped {
			fmt.Printf("Process %d: Completed snapshot %d\n", p.id, snapshotID)
			p.snapshots[snapshotID].Complete = true
			p.printSnapshot(snapshotID)
		}
	}
}

// Initiate a new snapshot
func (p *Process) InitiateSnapshot(allProcesses map[int]*Process) {
	snapshotID := int(time.Now().UnixNano() / 1e6) // Use timestamp as ID
	
	// Send marker to myself to start the process
	marker := Message{
		Type:       MarkerMessage,
		From:       p.id,
		To:         p.id,
		SnapshotID: snapshotID,
	}
	
	p.messages <- marker
	fmt.Printf("Process %d: Initiated snapshot %d\n", p.id, snapshotID)
}

// Print snapshot results
func (p *Process) printSnapshot(snapshotID int) {
	snapshot := p.snapshots[snapshotID]
	
	fmt.Printf("\n=== SNAPSHOT %d (Process %d) ===\n", snapshotID, p.id)
	fmt.Printf("Process State (Balance): %d\n", snapshot.ProcessState)
	fmt.Printf("Channel States:\n")
	for channelKey, messages := range snapshot.ChannelStates {
		fmt.Printf("  %s: %d messages recorded\n", channelKey, len(messages))
	}
	fmt.Printf("================================\n\n")
}

// Simulate sending application messages
func (p *Process) sendRandomMessage(allProcesses map[int]*Process) {
	if len(p.neighbors) > 0 {
		// Pick a random neighbor
		neighborID := p.neighbors[rand.Intn(len(p.neighbors))]
		
		msg := Message{
			Type:    AppMessage,
			From:    p.id,
			To:      neighborID,
			Content: "transfer",
		}
		
		allProcesses[neighborID].messages <- msg
		fmt.Printf("Process %d: Sent message to %d\n", p.id, neighborID)
	}
}

// Main demonstration
func main() {
	rand.Seed(time.Now().UnixNano())
	
	// Create 3 processes connected in a ring: 0-1-2-0
	processes := map[int]*Process{
		0: NewProcess(0, []int{1, 2}),
		1: NewProcess(1, []int{0, 2}),
		2: NewProcess(2, []int{0, 1}),
	}
	
	// Start all processes
	for _, p := range processes {
		p.Start(processes)
	}
	
	fmt.Println("=== System Started ===")
	time.Sleep(500 * time.Millisecond)
	
	// Simulate some application messages
	fmt.Println("\n=== Sending Messages ===")
	for i := 0; i < 5; i++ {
		for _, p := range processes {
			p.sendRandomMessage(processes)
		}
		time.Sleep(300 * time.Millisecond)
	}
	
	time.Sleep(1 * time.Second)
	
	// Take a snapshot
	fmt.Println("\n=== Taking Snapshot ===")
	processes[0].InitiateSnapshot(processes)
	
	time.Sleep(2 * time.Second)
	
	// Send more messages
	fmt.Println("\n=== Sending More Messages ===")
	for i := 0; i < 3; i++ {
		for _, p := range processes {
			p.sendRandomMessage(processes)
		}
		time.Sleep(300 * time.Millisecond)
	}
	
	time.Sleep(2 * time.Second)
	fmt.Println("=== Demo Complete ===")
}

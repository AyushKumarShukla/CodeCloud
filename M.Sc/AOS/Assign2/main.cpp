#include "Node.h"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;



int main(void){
	int SIZE;
	int CAND;
	int USER;
	int TIME = 0;
	vector<Node*> nodes;
	
	cout << "Enter the number of nodes in the network: " << endl;
	cin >> SIZE;
	
	for(int i=0;i<SIZE;i++)
		nodes.push_back(new Node(i));
	
	  // Print the addresses of the nodes
    cout << "\nAddresses of the nodes:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Node " << i << " address: " << nodes[i] << endl;
    }
    
    cout << "Choose Candidate: ";
    cin >> CAND;
    
    nodes[CAND]->wantsCS = true;
    
    cout << "Choose CS User: ";
    cin >> USER;
    
    nodes[USER]->inCS = true;
    
	for(int i=0;i<SIZE;i++){
	if(i==CAND)
		continue;
	nodes[i]->request(nodes[CAND], TIME);
	}
    nodes[CAND]->reqtime = TIME;
	cout << "GOAHEADS GRANTED BY: "<< endl;
	nodes[CAND]->printReplies();
	
	nodes[USER]->yield();
	cout << "\nGOAHEADS GRANTED BY AFTER YEILDING: "<< endl;
	nodes[CAND]->printReplies();
	
	if(nodes[CAND]->hasPermission(SIZE))
		nodes[CAND]->acquire();
		
	if(nodes[CAND]->inCS)
		cout << "\nCANDIDATE HAS ACQUIRED CS" << endl;
	return 0;
}





















/*-------------------------------------------------*/
/*
	int SIZE = 4;
	int CAND = 1;
	int SECCAND = 2;
	int USER = 3;
	int TIME = 0;
	vector<Node*> nodes;
	for(int i=0;i<SIZE;i++)
		nodes.push_back(new Node(i));
	
	nodes[CAND]->wantsCS = true;
	nodes[SECCAND]->wantsCS = true;
	
	nodes[USER]->inCS = true;
	
	for(int i=0;i<SIZE;i++){
		if(i==CAND)
			continue;
		nodes[i]->request(nodes[CAND], TIME);
	}
	nodes[CAND]->reqtime = TIME;
	cout << "GOAHEADS GRANTED BY: "<< endl;
	nodes[CAND]->printReplies();
	
	nodes[USER]->yield();
	cout << "\nGOAHEADS GRANTED BY AFTER YEILDING: "<< endl;
	nodes[CAND]->printReplies();
	
	if(nodes[CAND]->hasPermission(SIZE))
		nodes[CAND]->acquire();
		
	if(nodes[CAND]->inCS)
		cout << "\nCANDIDATE HAS ACQUIRED CS" << endl;
	return 0;
	*/
/*
SANDBOXED
int main(void){
	int SIZE = 4;
	int CANDIDATE = 1;
	int USER = 3;
	int TIME = 0;
	vector<Node> nodelist;
	vector<Node> candidates;
	
	for(int i=0;i<SIZE;i++){
		Node temp(i,SIZE);
		nodelist.push_back(temp);
	}
	
	// declare candidate
	nodelist[CANDIDATE].makeCandidate();
	candidates.push_back(nodelist[CANDIDATE]);
	
	//declare CS user
	nodelist[USER].makeCS();
	
	// make CS access request by candidates
	for(Node candidate: candidates){
		candidate.setTimestamp(TIME);
		for(Node node: nodelist){
			if(node.getid() == candidate.getid())
				continue;
			bool reply = node.requestCSAccess(candidate);
			cout << reply;
			cout << node.getid();
			if(reply == 0)
				candidate.logReply(node.getid());
		}
		TIME++;
	}
	
	candidates[0].checkAllReplies();
	
	std::cout << "NODE 3 LEAVING CS in 2 SECONDS" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2)); // sleep for 2 seconds
    std::cout << "GRANTING ACCESS NOW" << std::endl;
    
    nodelist[USER].yieldCS();
    
    candidates[0].checkAllReplies();
	
	return 0;
}
*/
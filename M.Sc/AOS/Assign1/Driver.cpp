#include <iostream>
#include "Graph.h"
#include "Node.h"

using namespace std;

int main() {
	int SIZE = 5;
	vector<Node*> nodelist(SIZE);
	
	for(int i=0;i<SIZE;i++){
		nodelist[i] = new Node(i);
	}
	
	for(Node* node: nodelist){
		node->setLists(SIZE);
	}
	
	//declaring candidates
	nodelist[0]->isCandidate = true;
	/*
    string filename = "matrix1.txt";
    
    Graph* graph = new Graph(Graph::getV(filename));
    graph->readFromFile(filename);
    graph->print();
	vector<int> inits = graph->getAllInitiators();
	
	cout << "Initiators: ";
	for(int val:inits)
		cout << val << " ";
	cout << endl;
	
    delete graph;
    */
    return 0;
}

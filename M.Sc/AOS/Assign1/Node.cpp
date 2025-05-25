#include "Node.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

Node::Node(int id){
	this->id = id;
	this->isCandidate = false;
	this->req_time = -1; 
}

void Node::setLists(int V){
		this->goaheads = vector<int>(V);
		this->toreply = vector<int>(V);
}
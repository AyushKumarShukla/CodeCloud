/*ASSIGNMENT 2 NODE*/
#include "Node.h"
using namespace::std;

Node::Node(int id, int V){
	this->id = id;
	this->req_time = -1;
	this-> is_candidate = false;
	this->is_CS = false;
	
	this->replies = vector<bool>(V-1);
	this->waiting_nodes = vector<bool>(V-1);
}

int Node::getid(){
	return this->id;
}

void Node::makeCandidate(){
	this->is_candidate = true;
}

bool Node::isCandidate(){
	return this->is_candidate;
}

void Node::makeCS(){
	this->is_CS = true;
}

bool Node::isCS(){
	return this->is_CS;
}

int Node::getTimestamp(){
	return this->req_time;
}

void Node::setTimestamp(int t){
	this->req_time = t;
}

void Node::logReply(int repid){
	this->replies[repid] = true;
}

bool Node::checkAllReplies(){
	for(bool safe : replies){
		if(!safe)
			return false;
	}
	return true;
}

void Node::addWaitingNode(int waitid){
	this->waiting_nodes[waitid] = true;
}





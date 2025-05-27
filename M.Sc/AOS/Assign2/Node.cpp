/*ASSIGNMENT 2 NODE*/
#include "Node.h"
#include<iostream>
using namespace::std;

Node::Node(int id){
	this->id = id;
	this->reqtime = 999;
	this->wantsCS = false;
	this->inCS = false;
}

int Node::getID(){
	return this->id;
}

void Node::goAhead(int id){
	this->replies.push_back(id);
}

bool Node::hasPermission(int SIZE){
	if(this->replies.size() == SIZE-1)
		return true;
	return false;
}

void Node::request(Node* req, int reqtimestamp){
	//current node is not a candidate, neither in CS
	if(!this->wantsCS && !this->inCS)
		req->goAhead(this->id);
	
	//current node is not a candidate but is in CS	
	if(!this->wantsCS && this->inCS)
		this->waiting.push_back(req);
		
	//current node is not in CS but is a candidate
	if(this->wantsCS && !this->inCS)
		if(this->reqtime > reqtimestamp)
			req->goAhead(this->id);
		else
			this->waiting.push_back(req);
	// a node cannot be a candidate while using the CS
	
}

void Node::printReplies(){
	for(int rep:this->replies)
		cout << rep << " ";
	cout << endl;
}

void Node::yield(){
	for(Node* req : this->waiting){
		req->goAhead(this->id);
	}
}

void Node::acquire(){
	this->inCS = true;
	this->wantsCS = false;
	this->reqtime = 999;
}





/*------------------------------------------------------------------*/
/*
SANDBOXED
Node::Node(int id, int V){
	this->id = id;
	this->req_time = -1;
	this-> is_candidate = false;
	this->is_CS = false;
	
	this->replies = vector<bool>(V);

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
	for(bool safe : replies)
		//cout << safe << endl;
		if(!safe)
			return false;
	return true;
	
}
void Node::addWaitingNode(Node req){
	this->waiting_nodes.push_back(req);
}

int Node::requestCSAccess(Node req){
	if(!this->is_CS)
		req.logReply(this->id);
	else{
		this->addWaitingNode(req);
	}
}

void Node::deferred_reply(int id){
	this->logReply(id);
}

void Node::yieldCS(){
	for(Node node:this->waiting_nodes)
		node.deferred_reply(this->id);
			
}
*/

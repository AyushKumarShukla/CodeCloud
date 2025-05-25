#include "Node.h"
#include<iostream>

int main(void){
	Node* n1 = new Node(1,4);
	Node* n2 = new Node(2,4);
	Node* n3 = new Node(3,4);
	Node* n4 = new Node(4,4);
	
	n2->makeCandidate();
	n3->makeCS();
	return 0;
}
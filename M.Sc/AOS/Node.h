#ifndef NODE_H
#define NODE_H
#include <vector>

using namespace std;

class Node{
	private:
		int id;
		bool wantsCS;
		bool inCS;
		
		vector<int> replies;
		vector<Node*> waiting;
		
	public:
		int getid();
		bool request(Node* req);
		void wait(Node* req);
		void yieldCS();		
};
#endif
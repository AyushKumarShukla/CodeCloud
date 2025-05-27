#ifndef NODE_H
#define NODE_H
#include<vector>
using namespace std;

class Node{
	public:
		int id;
		int reqtime;
		
		bool wantsCS;
		bool inCS;
		
		vector<Node*> waiting;
		vector<int> replies;
		

		Node(int id);
		int getID();
		void request(Node* req, int reqtime);
		void makeWait(Node* req);
		void goAhead(int id);
		bool hasPermission(int SIZE);
		void printReplies();
		void yield();
		void acquire();
	
};

#endif













/*-----------------------------------------------*/
/*
class Node{
	private:
		int id;
		int req_time;
		bool is_candidate;
		bool is_CS;
		
		vector<bool> replies;
		vector<Node> waiting_nodes;
		
	public:
		Node(int id,int V);
		int getid();
		
		void makeCandidate();
		bool isCandidate();
		
		void makeCS();
		bool isCS();
		
		int getTimestamp();
		void setTimestamp(int t);
		
		void logReply(int repid);
		bool checkAllReplies();
		
		void addWaitingNode(Node req);
		
		int requestCSAccess(Node req);
		
		void yieldCS();
		void deferred_reply(int id);
		
};
#endif
*/
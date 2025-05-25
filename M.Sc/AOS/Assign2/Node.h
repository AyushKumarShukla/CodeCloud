#ifndef NODE_H
#define NODE_H
#include<vector>
using namespace std;

class Node{
	private:
		int id;
		int req_time;
		bool is_candidate;
		bool is_CS;
		
		vector<bool> replies;
		vector<bool> waiting_nodes;
		
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
		
		void addWaitingNode(int waitid);
		
};
#endif
#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

using namespace std;

class Node {
private:
   

public:
	int id;
    int req_time;
    bool isCandidate;
	vector<int> goaheads;
    vector<int> toreply;
	Node(int id);
	void setLists(int V);
};

#endif

#include "Graph.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

Graph::Graph(int V) {
    this->V = V;
}

int Graph::getV(const string& filename) {
    int V;
    ifstream file(filename);
    if (!file) {
        cerr << "cannot open file" << endl;
        return 2;
    }
    file >> V;
    file.close();
    return V;
}

int Graph::readFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "cannot open file" << endl;
        return 1;
    }

    int val,skip;
    file >> skip;
    while (!file.eof()) {
        vector<int> row;
        for (int i = 0; i < this->V; i++) {
            file >> val;
            row.push_back(val);
        }
        this->adj.push_back(row);
    }

    file.close();
    return 0;
}

bool Graph::isInitiator(int start){
	vector<bool> visited(this->V,false);
	std::queue<int> q;
	q.push(start);
	while(!q.empty()){
		int current = q.front();
		for(int i=0;i<this->V;i++)
			if(this->adj[current][i] && !visited[i]){
				q.push(i);
				visited[i] = true;
			}
		q.pop();
	}
	for(int i=0;i<this->V;i++)
		if(!visited[i])
			return false;
	return true;
}

vector<int> Graph::getAllInitiators(){
	vector<int> inits;
	for(int i=0;i<this->V;i++)
		if(isInitiator(i))
			inits.push_back(i);
	return inits;
}

int Graph::getV(){
	return this->V;
}

void Graph::print() {
    for (const auto& row : this->adj) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}



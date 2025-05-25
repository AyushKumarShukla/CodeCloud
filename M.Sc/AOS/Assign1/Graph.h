#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V);
    static int getV(const string& filename);
    int readFromFile(const string& filename);
    bool isInitiator(int start);
    vector<int> getAllInitiators();
    int getV();
    void print();
};

#endif

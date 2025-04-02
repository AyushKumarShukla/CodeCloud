#include <stdio.h>
#include <vector>
#include <stack>

#define MAX_NODES 100  // Maximum nodes

std::vector<int> adj[MAX_NODES];  // Adjacency list

bool visited[MAX_NODES];          // Visited array
int dfs_nos[MAX_NODES];
int dfs_comp_nos[MAX_NODES];

int dfs_no = 0;
int dfs_comp_no;

void iterative_dfs(int start, int V) {
    std::stack<int> s;
    s.push(start);

    dfs_comp_no = V - 1; // Set the last completion number to 0 later

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (visited[node]) continue;
        
        printf("%d ", node);
        visited[node] = true;
        dfs_nos[node] = dfs_no++;

        // Push neighbors in reverse order for correct ordering
        for (int i = adj[node].size() - 1; i >= 0; i--) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                s.push(neighbor);
            }
        }
        dfs_comp_nos[node] = dfs_comp_no--;
    }
}

int main() {
    int V, E;  // Number of vertices and edges

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter edges (u v format, 0-based index):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);  // For undirected graph
    }

    // Initialize visited array
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    printf("DFS traversal: ");
    iterative_dfs(0, V);  // Start DFS from node 0
    
    printf("\nDFS NUMBERS: \n");
    for (int i = 0; i < V; i++) {
        printf("%d\t", dfs_nos[i]);
    }
    
    printf("\nDFS COMPLETION NUMBERS: \n");
    for (int i = 0; i < V; i++) {
        printf("%d\t", dfs_comp_nos[i]);
    }
    printf("\n");

    return 0;
}


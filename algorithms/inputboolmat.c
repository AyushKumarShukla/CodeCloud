#include <stdio.h>
#include <stdbool.h>

void initializeMatrix(int v, bool** adj) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            adj[i][j] = false;
        }
    }
}

void printMatrix(int v, bool** adj) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            printf("%d\t", adj[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int v;
    printf("To color the vertices of a graph using backtracking\n");
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &v);

    bool adj[v][v];
    initializeMatrix(v, adj);

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < v; i++) {
        printf("Enter the number of vertices adjacent to vertex %d: ", i);
        int num;
        scanf("%d", &num);
        for (int j = 0; j < num; j++) {
            printf("Enter vertex number: ");
            int temp;
            scanf("%d", &temp);
            adj[i][temp] = true;
        }
    }

    printf("Adjacency matrix of the graph:\n");
    printMatrix(v, adj);

    return 0;
}


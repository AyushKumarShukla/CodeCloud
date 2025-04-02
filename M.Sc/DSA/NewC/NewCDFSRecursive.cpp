#include <vector>
#include <stack>
#include <stdio.h>

#define MAX 10

using namespace std;

int V,E;
bool visited[MAX] = {};
vector<int> adj[MAX];

void dfs(int start){
	if(visited[start]) return;
	
	visited[start] = true;
	printf("%d ",start);
	for(int neighbour: adj[start]){
		dfs(neighbour);
	}
}

int main(void){
	// input dimensions
	printf("Enter V: ");
	scanf("%d",&V);
	printf("Enter E: ");
	scanf("%d",&E);
	
	int u,v;
	// input graph
	printf("Enter %d Edges: \n",E);
	for(int i=0;i<E;i++){
		printf("Enter an edge (u,v): ");
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
	}	
	
	// display entered graph
	printf("Adjacency List: \n");
	for(int i=0;i<V;i++){
		printf("[%d]--> ",i);
		if(adj[i].size() == 0){
			printf("NULL\n");
			continue;
		}
		for(int j=0;j<adj[i].size();j++)
			printf("%d\t", adj[i].at(j));
		printf("\n");
	}
	
	//get a start vertex
	int start;
	printf("Enter the start vertex for DFS: ");
	scanf("%d",&start);
	dfs(start);
}

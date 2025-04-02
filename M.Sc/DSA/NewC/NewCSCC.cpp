#include <vector>
#include <stack>
#include <stdio.h>

#define MAX 10
#define UNVISITED -1

using namespace std;

int V,E;
bool visited[MAX] = {};
vector<int> adj[MAX];

int id=0;
int scc_count=0;

int ids[MAX] = {};
int low[MAX] = {};
bool onStack[MAX] = {};

stack<int> s;


void dfs(int at){
	s.push(at);
	onStack[at] = true;
	ids[at] = low[at] = id++;
	
	for(int to: adj[at]){
		if(ids[to] == UNVISITED)
			dfs(to);
		if(onStack[to])
			low[at] = min(low[at],low[to]);
	}
	
	if(ids[at] == low[at]){
		while(true){
			int node = s.top();
			s.pop();
			onStack[node] = false;
			low[node] = ids[at];
			if(node == at)
				break;
		}
		scc_count++;
	}
}

void findSCC(){
	for(int i=0;i<V;i++)
		ids[i] = UNVISITED;
		
	for(int i=0;i<V;i++){
		if(ids[i] == UNVISITED){
			dfs(i);
		}
	}
	
	for(int i=0;i<V;i++){
		printf("%d ",low[i]);
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
	
	findSCC();
	
	/*
	//get a start vertex
	int start;
	printf("Enter the start vertex for DFS: ");
	scanf("%d",&start);
	dfs(start);
	*/
}

#include <vector>
#include <stdio.h>
#include <stack>
#define	MAX 20
using namespace std;

int V,E;
vector<vector<int>> G(MAX,vector<int>(MAX,0));
bool visited[MAX] = {};

void dfs(vector<vector<int>>& G, int start){
	stack<int> S;
	S.push(start);
	
	while(!S.empty()){
		int node = S.top();
		S.pop();
		
		if(visited[node]) continue;
		
		visited[node] = true;
		printf("%d ",node);
		
		for(int i=V-1;i>=0;i--)
			if(G[node][i]){
				int neighbour = i;
				if(!visited[i])
					S.push(i);
			}
	}
}

int main(void){
	
	scanf("%d%d",&V,&E); 
	
	for(int i=0;i<E;i++){
		int u,v;
		printf("Enter Edge (u,v): ");
		scanf("%d%d",&u,&v);
		G[u][v] = 1;
	}
	
	for(int i=0;i<V;i++){
		printf("\n");
		for(int j=0;j<V;j++)
			printf("%d\t",G[i][j]);
	}
	
	int start;
	printf("start: ");
	scanf("%d",&start);
	dfs(G,start);
}	
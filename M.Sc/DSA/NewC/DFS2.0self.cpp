#include <vector>
#include <memory>
#include <stack>

using std::vector;
using std::move;
using std::unique_ptr;
void dfs(unique_ptr<int> graph,bool visited[], int start){
	if(!visited[start]){
		printf("%d",start);
		visited[start] = true;
		for(int adj: graph[start])
			dfs(graph,visited,adj);
	}
	else return;
}

int main(void){
	int MAX=10;
	vector<int> graph[MAX];
	bool visited[MAX];
	int V,E;
	int u,v;
	printf("Enter the number of vertices: ");
	scanf("%d",&V);
	printf("\n Enter the number of edges: ");
	scanf("%d",&E);
	
	for(int i=0;i<E;i++){
		printf("Enter %d edges: ",E);
		scanf("%d %d",&u,&v);
		graph[u].push_back(v);
	}
	
	for(int i=0;i<V;i++){
		printf("\n");
		printf("[%d]\t",i);
		for(int j=0;j<graph[i].size();j++)
			printf("%d\t",graph[i].at(j));
	}
	
	for(int i=0;i<MAX;i++)
		visited[i] = false;
		
	int start = 0;
	dfs(move(graph),visited, start);
}

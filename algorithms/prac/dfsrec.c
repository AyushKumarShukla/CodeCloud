#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void getmatrix(bool(*adj)[20],int v)
{
	int i,j,num,temp;
	for(i=0;i<v;i++)
	{
		printf("Enter number of vertices adjacent to vertex %d: ",i);
		scanf("%d",&num);
		for(j=0;j<num;j++)
		{
			printf("Enter vertex number: ");
			scanf("%d",&temp);
			adj[i][temp]=true;
		}
	}
}

void dispmatrix(bool(*adj)[20],int v)
{
	int i,j;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
			printf("%d\t",adj[i][j]);
		printf("\n");
	}
}

void dfs(int vertex,int size,bool(*adj)[20],bool* visited,int* parent)
{
	int i;
	visited[vertex]=true;
	printf("%d\t",vertex);
	for(i=0;i<size;i++)
	{
		if(adj[vertex][i] && !visited[i])
		{
			parent[i]=vertex;
			dfs(i,size,adj,visited,parent);
		}
	}
}

void disptree(int* parent,int v)
{
	int i;
	printf("PARENT:\t");
	for(i=0;i<v;i++)
		printf("%d\t",parent[i]);
	printf("\nVERTEX:\t");
	for(i=0;i<v;i++)
		printf("%d\t",i);
}
int main(void)
{
	bool adj[20][20],visited[20];
	int parent[20],v,s;
	int i,j;
	printf("Enter the number of vertices in the graph :");
	scanf("%d",&v);
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			adj[i][j]=false,parent[i]=-1;
	printf("Enter the adjacency matrix:\n");
	getmatrix(adj,v);
	printf("Entered adjacency matrix:\n");
	dispmatrix(adj,v);
	printf("TRAVERSAL SEQUENCE: ");
	dfs(s,v,adj,visited,parent);
	printf("\nDFS TREE:\n");
	disptree(parent,v);
		
}

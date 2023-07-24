#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void disp_mat(bool(*adj)[20],int v)
{
	for(int i=0;i<v;i++)
	{
		printf("V%d\t",i);
		for(int j=0;j<v;j++)
			printf("%d\t",adj[i][j]);
		printf("\n");
	}
}
//to initialise all entries of adjacency matrix to false
void init_to_zero(bool(*adj)[20],int v)
{
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			adj[i][j]=false;
}

void get_matrix(bool(*adj)[20],int v)
{
	for(int i=0;i<v;i++)
	{
		printf("Enter number of vertices adjacent to vertex %d: ",i);
		int num;
		scanf("%d",&num);
		for(int j=0;j<num;j++)
		{
			printf("Enter vertex number: ");
			int temp;
			scanf("%d",&temp);
			adj[i][temp]=true;
		}
	}
}

void dfs(int vertex,int size,bool(*adj)[20],bool* visited,int* parent)
{
	int i;
	visited[vertex]=true;//vertex is visited
	printf("%d\t",vertex);
	for(i=0;i<size;i++)
		//if adjacent vertex i has not been visited
		if(adj[vertex][i] && !visited[i])
		{
			parent[i]=vertex; //set vertex as parent of i
			dfs(i,size,adj,visited,parent); //visited i recursively
		}
}

int main(void)
{
	int v,i,s,parent[20];
	bool adj[20][20],visited[20];
	printf("To perform Depth First Search recursively: \n");
	printf("Enter the number of vertices in the graph: ");
	scanf("%d",&v);
 	//initialising visited and parent arrays
	for(i=0;i<v;i++)
	{
		visited[i]=false; //tells whether vertex has been visited
		parent[i]=-1; //holds the parent vertex of a vertex
	}
	printf("Enter the adjacency matrix of the graph :\n");
	get_matrix(adj,v);
	printf("Entered Adjacency Matrix: \n");
	printf("\t");
	for(i=0;i<v;i++)
		printf("V%d\t",i);
	printf("\n");
	disp_mat(adj,v);	
	printf("\nEnter the source vertex: ");
	scanf("%d",&s);
	printf("DFS traversal: \n");
	dfs(s,v,adj,visited,parent); //start recursion with source vertex
	//printing result after DFS traversal
	printf("\nParent list:\n");
	printf("PARENT: ");
	for(i=0;i<v;i++)
		printf("%d\t",parent[i]);
	printf("\n");
	printf("VERTEX: ");
	for(i=0;i<v;i++)
		printf("%d\t",i);
	printf("\n");
	return 0;
}













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
//function to initialise adjacency matrix entries to false
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
void warshall(bool(*adj)[20],int v)
{
	int inter,src,des;
	for(inter=0;inter<v;inter++) //select intermediate vertex
		for(src=0;src<v;src++) //select source vertex
			for(des=0;des<v;des++) //select destination vertex
				//if a direct edge OR a path through intermediate vertex exists
 				//set path status to true
				adj[src][des]=adj[src][des]||(adj[src][inter] && adj[inter][des]);
}
//function to print heading for adjacency matrix display
void print_heading(int v)
{	
	int i;
	printf("\t");
	for(i=0;i<v;i++)
		printf("V%d\t",i);
	printf("\n");
}

int main(void)
{
	int color[20],v,i,m;
	bool adj[20][20];
	printf("To Find Existing Paths Using Warshall Algorithm: \n");
	printf("Enter the number of vertices in the graph: ");
	scanf("%d",&v);
	printf("Enter the adjacency matrix of the graph :\n");
	get_matrix(adj,v);
	printf("Entered Adjacency Matrix: \n");
	print_heading(v);
	disp_mat(adj,v);
	printf("After applying Warshall's algorithm: \n");
	printf("Modified adjacency matrix:  \n");
	warshall(adj,v);
	print_heading(v);
	disp_mat(adj,v);
	printf("\n");
	return 0;
}












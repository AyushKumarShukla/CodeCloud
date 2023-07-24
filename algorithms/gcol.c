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

void init_to_zero(bool(*adj)[20],int v)
{
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			adj[i][j]=false;
}

bool colorvertices(bool(*adj)[20],int* color,int vertices,int m,int i)
{
	int j,k;
	bool valid;
	if(i==vertices)
		return true;
	for(j=0;j<m;j++)
	{
		valid=true;
		for(k=0;k<vertices;k++)
		{
			if(adj[i][k] && (j==color[k]))
			{
				valid=false;
				break;
			}
		}
		if(!valid)
			continue;
		color[i]=j;
		if(colorvertices(adj,color,vertices,m,i+1))
			return true;
		else
			color[i]=-1;
		
	}
	return false;
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
int main(void)
{
	int color[20],v,i,m;
	bool adj[20][20];
	printf("To color the vertices of a graph using backtracking\n");
	printf("Enter the number of vertices in the graph: ");
	scanf("%d",&v);
	printf("Enter the number of colors (m): ");
	scanf("%d",&m);
	//initialising the color list with -1 representing no color
	for(i=0;i<v;i++)
		color[i]=-1;
	printf("Enter the adjacency matrix of the graph :\n");
	get_matrix(adj,v);
	printf("Entered Adjacency Matrix: \n");
	printf("\t");
	for(i=0;i<v;i++)
		printf("V%d\t",i);
	printf("\n");
	disp_mat(adj,v);
	if(!colorvertices(adj,color,v,m,0))
	{
		printf("Graph cannot be colored with %d color(s)\n",m);
		return 1;
	}
	else
	{
		printf("Graph colored successfully");
		printf("\nResultant color list: \n");
		printf("Vertices:\t");
		for(i=0;i<v;i++)
			printf("%d\t",i);
		printf("\n");
		printf("Colors:  \t");
		for(i=0;i<v;i++)
			printf("%d\t",color[i]);
	}
	printf("\n");
	return 0;
}












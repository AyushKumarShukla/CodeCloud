#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//initialise all elements of matrix to 0 
void init_mat(int (*mat)[20],int v)
{
	int i,j;
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			mat[i][j]=0;
}
void get_adj_mat(int (*mat)[20],int v)
{
	int i,j,vnum,temp;
	for(i=0;i<v;i++)
	{
		printf("Enter the no of vertices connected to V%d: ",i);
		scanf("%d",&vnum);
		for(j=0;j<vnum;j++)
		{
			printf("Enter vertex number: ");
			scanf("%d",&temp);
			mat[i][temp]=1;
		}
	}
}
void disp_mat(int (*mat)[20],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		printf("V%d\t",i);
		for(j=0;j<col;j++)
			printf("%d\t",mat[i][j]);
		printf("\n");
	}

}
int adj_to_inc(int(*adj)[20],int(*inc)[20],int v)
{
	int nume,i,j,k;
	k=0;
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
		{
			if(adj[i][j]==1 && j<i) //traversing the upper triangular matrix for undirected graph
			{
				inc[i][k]=1;
				inc[j][k]=1;
				k++;
			}
		}
	return k;
}
//to print the matrix column headings
void print_header(char pre,int e)
{
	int i;
	printf("V/%c\t",pre);
	for(i=0;i<e;i++)
		printf("%c%d\t",pre,i);
	printf("\n");
}
int main(void)
{
	int adj[20][20],inc[20][20];
	int v,nume;
	printf("To convert the adjacency matrix to the incidence matrix: ");
	printf("\nEnter the number of vertices in the graph: ");
	scanf("%d",&v);
	printf("Enter the number of edges in the graph: ");
	scanf("%d",&nume);
	//initialise matrices
	init_mat(adj,v);
	init_mat(inc,20);
	printf("Enter the adjacency matrix:\n");
	get_adj_mat(adj,v);
	printf("Entered Adjacency Matrix:\n");
	print_header('V',v);
	disp_mat(adj,v,v);
	adj_to_inc(adj,inc,v);
	printf("Equivalent Incidence Matrix:\n");
	print_header('I',nume);
	disp_mat(inc,v,nume);
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//initialise all elements to 0
void init_mat(int (*mat)[20],int v)
{
	int i,j;
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			mat[i][j]=0;
}
void get_inc_mat(int (*mat)[20],int e)
{
	int i,j,v1,v2;
	for(j=0;j<e;j++)
	{
		printf("Enter incident vertices on E%d: ",j);
		scanf("%d%d",&v1,&v2);
		mat[v1][j]=1;
		mat[v2][j]=1;
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
void inc_to_adj(int(*inc)[20],int(*adj)[20],int v,int e)
{
	//arr has size of 2, the indices hold start and end vertices of an edge respectively
	int arr[2],i,j,k;
	for(j=0;j<e;j++)
	{
		k=0;
		for(i=0;i<v;i++)
			if(inc[i][j]==1)
			{
				arr[k]=i;	
				k+=1;
			}
		//update values in adj
		adj[arr[0]][arr[1]]=1;
		adj[arr[1]][arr[0]]=1;
	}

}
//to print the matrix row headings
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
	int v,e;
	printf("To convert the adjacency matrix to the incidence matrix: ");
	printf("\nEnter the number of vertices in the graph: ");
	scanf("%d",&v);
	printf("Enter the number of edges in the graph: ");
	scanf("%d",&e);
	//initialise matrices
	init_mat(adj,v);
	init_mat(inc,20);
	printf("Enter the Incidency matrix\n");
	get_inc_mat(inc,e);
	printf("Entered incidency Matrix:\n");
	print_header('I',e);
	disp_mat(inc,v,e);
	printf("Equivalent Adjacency Matrix: \n");
	print_header('V',v);
	inc_to_adj(inc,adj,v,e);
	disp_mat(adj,v,v);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//constructing adjencency matrix for a graph

void init_mat(int(*mat)[20],int ord)
{
	int i,j;
	for(i=0;i<20;i++)
		for(j=0;j<20;j++)
			if(i==j)
				mat[i][j]=0;
			else if(i!=j && i>ord)
				mat[i][j]=0;
			else
				mat[i][j]=999;
}


void get_mat(int(*mat)[20],int v,int e)
{
	int i,x,y;
	for(i=0;i<e;i++)
	{
		printf("Enter the first end vertex of %dth edge: ",i);
		scanf("%d",&x);
		printf("Enter the second end vertex of %dth edge: ",i);
		scanf("%d",&y);
		//array indices always have to be ints
		mat[x][y]=1;
		mat[y][x]=1;
		//incidence matrix
		mat[x][i+v]=1;
		mat[y][i+v]=1;
	}
}

void disp_mat(int(*mat)[20],int v)
{
	int i,j;
	for(i=0;i<v;i++)
	{
		printf("V%d\t",i);
		for(j=0;j<2*v;j++)
			printf("%d\t",mat[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int mat[20][20],v,e;
	printf("Enter the number of vertices in the graph: ");
	scanf("%d",&v);
	printf("Enter the number of edges  in the graph: ");
	scanf("%d",&e);
	memset(mat,0,sizeof(mat));
	init_mat(mat,v);	
	printf("Enter the adjacency matrix: \n");
	get_mat(mat,e,v);
	printf("Entered adjacency matrix: \n");
	disp_mat(mat,v);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void get_mat(double(*mat)[20], int v)
{
	int i,j;
	double inp;
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
		{
			printf("Weight of path from V%d to V%d: ",i+1,j+1);
			scanf("%lf",&inp);
			if(inp==9)
				mat[i][j]=(1.0/0.0);
			else
				mat[i][j]=inp;
		}
}

void disp_mat(double(*mat)[20], int v)
{
	int i,j;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
			printf("%.0lf\t",mat[i][j]);
		printf("\n");
	}
}

void floyd_warshall(double(*mat)[20], int v)
{
	int i,j,k;
	double sum;
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			for(k=0;k<v;k++)
			{
				sum=mat[j][i]+mat[i][k];
				if(sum<mat[j][k])
					mat[j][k]=sum;
			}
}

int main(void)
{
	int v,e;
	double mat[20][20];
	printf("To find the minimum cost traversal matrix for a graph: ");
	printf("\nEnter the number of vertices in the graph: ");
	scanf("%d",&v);
	printf("\nEnter the number of edges in the graph: ");
	scanf("%d",&e);
	get_mat(mat,v);
	printf("Entered Adjacency Matrix:\n");
	disp_mat(mat,v);
	floyd_warshall(mat,v);
	printf("Minimum Cost Matrix:\n");
	disp_mat(mat,v);
	return 0;
}

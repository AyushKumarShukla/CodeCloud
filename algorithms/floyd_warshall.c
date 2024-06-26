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
			printf("Weight of path from V%d to V%d: ",i,j);
			scanf("%lf",&inp);
			//to input infinity, the value 999 has been chosen arbitrarily
			if(inp==999)
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
		printf("V%d\t",i);
		for(j=0;j<v;j++)
			printf("%.0lf\t",mat[i][j]);
		printf("\n");
	}
}

void floyd_warshall(double(*mat)[20], int v)
{
	int i,j,k;
	double sum;
	for(i=0;i<v;i++) //intermediate vertex
		for(j=0;j<v;j++) //source vertex
		{
			sum=0;
			for(k=0;k<v;k++) //destination vertex
			{
				sum=mat[j][i]+mat[i][k];
				//if path through intermediate vertex is shorter
				if(sum<mat[j][k])
					mat[j][k]=sum; //update the weight of edge
			}
		}
}

void print_headers(int v)
{
	int i;
	printf("\t");
	for(i=0;i<v;i++)
		printf("V%d\t",i);
	printf("\n");
}
int main(void)
{
	int v;
	double mat[20][20];
	printf("To find shortest distance matrix of a graph using Floyd-Warshall Algorithm: ");
	printf("\nEnter the number of vertices in the graph: ");
	scanf("%d",&v);
	get_mat(mat,v);
	printf("Entered Adjacency Matrix:\n");
	print_headers(v);
	disp_mat(mat,v);
	floyd_warshall(mat,v);
	printf("\nMinimum Cost Matrix:\n");
	print_headers(v);
	disp_mat(mat,v);
	return 0;
}

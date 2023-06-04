#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//display the adjacency matrix
void disp_mat(int(*mat)[20],int v)
{
	int i,j;
	for(i=0;i<v;i++)
	{
		printf("V%d\t",i);
		for(j=0;j<v;j++)
			printf("%d\t",mat[i][j]);
		printf("\n");
	}
}

void get_mat(int(*mat)[20],int v)
{
	int i,j;
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			{
				printf("Enter w(V%d,V%d): ",i,j);
				scanf("%d",&mat[i][j]);
			}
}

int main(void)
{
	int mat[20][20],v,i;
	printf("Enter the number of vertices in the graph: ");
	scanf("%d",&v);
	printf("Enter the adjacency matrix: \n");
	get_mat(mat,v);
	printf("Entered adjacency matrix: \n");
	printf("Vn\t");
	//printing matrix headings
	for(i=0;i<v;i++)
		printf("V%d\t",i);
	printf("\n");
	disp_mat(mat,v);
	return 0;
}

/*Implementation: Unweighted Undirected Graph
Author: Ayush Kumar Shukla
Date: 13-11-24 --> v1.0
*/
#include <stdio.h>

void inputMat(int(*adj)[20],int vertexcnt,bool DIRECTED,bool WEIGHTED)
{
	int i,j;
	
	for(i=0;i<vertexcnt;i++)
		for(j = DIRECTED ? 0:i;j<vertexcnt;j++)
		{
			scanf("%d",&adj[i][j]);
			if(!DIRECTED)
				adj[j][i] = adj[i][j];
		}
}

void showMat(int(*adj)[20],int vertexcnt)
{
	int i,j;
	for(i=0;i<vertexcnt;i++)
	{
		for(j=0;j<vertexcnt;j++)
			printf("%d\t",adj[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int adj[20][20],vertexcnt;
	int i,j;
	bool DIRECTED,WEIGHTED;
	int ch;
	
	printf("MENU:\n1.Undirected Unweighted\n2.Undirected Weighted\n3.Directed Unweighted\n4.Directed Weighted\n");
	printf("Enter type of matrix: ");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			DIRECTED = false;
			WEIGHTED = false;
			break;
		case 2:
			DIRECTED = false;
			WEIGHTED = true;
			break;
		case 3:
			DIRECTED = true;
			WEIGHTED = false;
			break;
		case 4:
			DIRECTED = true;
			WEIGHTED = true;
			break;
	}
	
	printf("Enter the number of vertices in the graph:\t");
	scanf("%d",&vertexcnt);
	
	printf("Enter the adjacency matrix:\n");
	inputMat(adj,vertexcnt,DIRECTED,WEIGHTED);
			
	printf("Entered adjacency matrix:\n");
	showMat(adj,vertexcnt);
	
	return 0;
}

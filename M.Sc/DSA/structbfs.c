#include<stdio.h>
#define MAX 20

typedef struct{
	double values[MAX];
	int rear;
	int front;
}Queue;

typedef struct{
	int values[MAX][MAX];
	int vcount;
	int ecount;
}Graph;

void initGraph(Graph* graph,int vcount,int ecount)
{
	int i,j;
	graph->vcount = vcount;
	graph->ecount = ecount;
	
	for(i=0;i<vcount;i++)
		for(j=0;j<vcount;j++)
			graph->values[i][j] = 0;
}

void inputGraph(Graph* graph)
{
	int i;
	int source,dest;
	for(i=0;i<graph->ecount;i++)
	{
		printf("Enter the vertices of edge %d: ",i+1);
		scanf("%d %d",&source,&dest);
		graph->values[source][dest] = 1;
		graph->values[dest][source] = 1;
	}
}

void showGraph(Graph* graph)
{
	int i,j;
	for(i=0;i<graph->vcount;i++)
	{
		for(j=0;j<graph->vcount;j++)
			printf("%d\t",graph->values[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int vcount,ecount;
	Graph graph;
	
	printf("Enter the number of vertices: ");
	scanf("%d",&vcount);
	printf("Enter the number of edges: ");
	scanf("%d",&ecount);
	
	initGraph(&graph,vcount,ecount);
	inputGraph(&graph);
	showGraph(&graph);
	return 0;
}

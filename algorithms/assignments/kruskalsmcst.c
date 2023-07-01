#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node
{
	int u;int v;int w;
}node;

void get_edges(node* edges,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter (u,v,w) for edge %d: ",i);
		scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].w);
	}
}

void disp_edges(node* edges,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("EDGE %d: V%d<-->V%d W(%d)\n",i,edges[i].u,edges[i].v,edges[i].w);
}

int compedges(const void* a,const void* b)
{
	node* edgeA=(node*)a;
	node* edgeB=(node*)b;
	return(edgeA->w-edgeB->w);
}

//finding representative element aka root of the set-object
int findroot(int* parent,int vertex)
{
	int index,par;
	index=vertex;
	par=parent[index];
	while(par!=-1)
	{
		index=par;
		par=parent[index];
	}
	return index;
}

int kruskalsmcst(node* edges,int* parent,int nume)
{
	int i,uroot,vroot,cost=0;
	for(i=0;i<nume;i++)
	{
		uroot=findroot(parent,edges[i].u);
		vroot=findroot(parent,edges[i].v);
		if(uroot!=vroot || (uroot==-1 && vroot==-1)) //FINDSET
		{
			parent[vroot]=uroot; //UNION 
			printf("V%d<-->V%d W(%d) \n",edges[i].u,edges[i].v,edges[i].w);
			cost+=edges[i].w;
		}
	}
	return cost;
}

// MAKESET
void init_parent(int* parent,int numv)
{
	int i;
	for(i=0;i<numv;i++)
		parent[i]=-1;
}

int main(void)
{
	node edges[20];	
	//parent array item is the set-object in which a vertex belongs
	int parent[20],numv,nume,cost;
	printf("To Find The MST of a graph using Kruskal's Algorithm:\n");
	printf("Enter the number of vertices in the graph: ");
	scanf("%d",&numv);	
	if(numv<1)
	{
		printf("Invalid Input, Atleast 1 Vertex Needed\n");
		exit(0);
	}
	printf("Enter the number of edges in the graph: ");
	scanf("%d",&nume);
	if(nume<1)
	{
		printf("Invalid Input, Atleast 1 Edge Needed\n");
		exit(0);
	}
	init_parent(parent,numv);
	get_edges(edges,nume);
	printf("\nEntered list of edges: \n");
	disp_edges(edges,nume);
	qsort(edges,nume,sizeof(node),compedges);
	printf("\nAfter Sorting Edges By Weight:\n");
	disp_edges(edges,nume);
	printf("\nEdges in the MCST are: \n");
	cost=kruskalsmcst(edges,parent,nume);
	printf("Minimum Cost: %d\n",cost);
	return 0;
}

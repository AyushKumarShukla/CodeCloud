#include<stdio.h>
#define ROOT -1
typedef struct node
{
	int u;int v;int w;
}edge;

void get_edges(edge* edges,int e)
{
	int i;
	for(i=0;i<e;i++)
	{
		printf("Enter (u,v,w) for edge %d: ",i);
		scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].w);
	}
}

void disp_edges(edge* edges,int e)
{
	int i;
	for(i=0;i<e;i++)
		printf("Edge %d: (%d,%d,%d)\n",i,edges[i].u,edges[i].v,edges[i].w);
	
}

void sort_edges(edge* edges,int e)
{
	int i,j;
	edge temp;
	for(i=0;i<e;i++)
		for(j=0;j<e-i-1;j++)
			if(edges[i].w>edges[i+1].w)
			{
				temp=edges[i];
				edges[i]=edges[i+1];
				edges[i+1]=temp;
			}	
}

void init_parent(int* parent,int v)
{
	int i;
	for(i=0;i<v;i++)
		parent[i]=ROOT;
}

int findroot(int* parent,int vertex)
{
	int index,par;
	index=vertex;
	par=parent[index];
	while(par!=ROOT)
	{
		index=par;
		par=parent[index];
	}
	return index;
}

int kruskal_MST(edge* edges,int* parent,int e)
{
	int i,uroot,vroot;	
	for(i=0;i<e;i++)
	{
		uroot=findroot(parent,edges[i].u);
		vroot=findroot(parent,edges[i].v);
		if(uroot!=vroot || ((uroot==ROOT) && (vroot==-1)))
		{
			parent[vroot]=uroot;
			printf("\nEdge %d: (%d,%d,%d)",i,edges[i].u,edges[i].v,edges[i].w);
		}
	}
}
int main(void)
{
	int parent[20],v,e,cost;
	edge edges[20];	
	printf("Enter the number of vertices in the graph: ");
	scanf("%d",&v);
	printf("Enter the number of edges in the graph: ");
	scanf("%d",&e);
	get_edges(edges,e);
	printf("Entered Edge List: \n");
	disp_edges(edges,e);
	sort_edges(edges,e);
	printf("Sorted Edge List: \n");
	disp_edges(edges,e);
	init_parent(parent,v);
	printf("Edges in the MST are: ");
	cost=kruskal_MST(edges,parent,e);
	printf("\n");
	return 0;
	
}

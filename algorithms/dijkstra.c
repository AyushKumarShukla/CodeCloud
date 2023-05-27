#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


typedef struct node
{
	int data;
	int weight;
	struct node *next;
}node;

typedef struct vertex
{
	int minweight;
	int visited;
}vertex;

node* createnode(int item,int vw)
{
	node *temp=(node*)malloc(sizeof(node));
	temp->next=NULL;
	temp->data=item;
	temp->weight=vw;
	return temp;
}

node* insert_at_end(node* start, int item,int vw)
{
	node *temp, *ptr;
	temp=createnode(item,vw);
	if(start==NULL)
		start=temp;
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=temp;
	}
	return start;
}

void disp_adjlist(node** adj,int v)
{
	node* temp;
	int i;
	for(i=0;i<v;i++)
	{
		printf("V%d: ",i);
		temp=adj[i];
		while(temp!=NULL)
		{
			printf("(%d,%d)",temp->data,temp->weight);
			temp=temp->next;
		}
		printf("\n");
	}
}

void get_adjlist(node **adj,int v)
{
	int i,temp,j,vnum,vw;
	for(i=0;i<v;i++)
	{
		printf("Enter number of vertices connected to V%d: ",i);
		scanf("%d",&temp);
		for(j=0;j<temp;j++)
		{
			printf("Enter (V,W): ");
			scanf("%d%d",&vnum,&vw);
			adj[i]=insert_at_end(adj[i],vnum,vw);
		}
	}
}

void init_adj(node** adj,int v)
{
	int i;
	for(i=0;i<v;i++)
		adj[i]=NULL;
}

void init_varr(vertex* varr,int v,int source)
{
	int i;
	for(i=0;i<v;i++)
	{
		if(i==source)
			varr[i].minweight=0;
		else
			varr[i].minweight=999;
		varr[i].visited=0;
	}
}

void disp_varr(vertex* varr,int v)
{
	int i;
	for(i=0;i<v;i++)
		printf("Weight Of Path to V%d : %d\n",i,varr[i].minweight);
}

int extract_min(vertex* varr,int v)
{
	int minindex,minval,cw=0,i;
	for(i=0;i<v;i++)
	{
		if(varr[i].visited==0)
		{
			minindex=i;
			break;
		}
	}

	minval=varr[minindex].minweight;
	for(i=1;i<v;i++)
	{
		cw=varr[i].minweight;
		if(cw<minval && varr[i].visited==0)
		{
			minindex=i;
			minval=cw;
		}
	}
	return minindex;
}

int dijkstra(node** adjlist,vertex* varr,int v)
{
	int i,index,CN=0,CW=0,TC=0,cost=0;
	node* trav=NULL;
	for(i=0;i<v;i++)
	{
		index=extract_min(varr,v);
		trav=adjlist[index];
		while(trav!=NULL)
		{
			CN=trav->data;
			CW=trav->weight;
			TC=(CW+varr[index].minweight); //total cost of path from src to the node
			if(TC<varr[CN].minweight && varr[CN].visited==0)
				varr[CN].minweight=TC;
			trav=trav->next;
		}
		varr[index].visited=1;
		cost+=varr[index].minweight;
	}
	return cost;
}

int main(void)
{
	int item,v,i,s,cost=0;
	node* adj[20];
	vertex varr[20];
	printf("Enter the number of vertices in the graph : ");
	scanf("%d",&v);
	init_adj(adj,v);
	get_adjlist(adj,v);
	disp_adjlist(adj,v);
	printf("Enter the source vertex: ");
	scanf("%d",&s);
	init_varr(varr,v,s);
	printf("Initial State:\n");
	disp_varr(varr,v);
	//printf("Vertices In The Path Are: \n");
	cost=dijkstra(adj,varr,v);
	printf("\nFinal State:\n");
	disp_varr(varr,v);
	printf("\nTotal Weight Of All Shortest Paths: %d\n",cost);
	return 0;
}


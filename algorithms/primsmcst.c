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
		printf("(%d,%d)",varr[i].minweight,varr[i].visited);
	printf("\n");
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
int primsmcst(node** adjlist,vertex* varr,int v)
{
	int i,index,CN,CW,cost=0;
	node* trav=NULL;
	for(i=0;i<v;i++)
	{
		index=extract_min(varr,v);
		trav=adjlist[index];
		while(trav!=NULL)
		{
			CN=trav->data;
			CW=trav->weight;
			if(CW<varr[CN].minweight && varr[CN].visited==0)
				varr[CN].minweight=CW;
			trav=trav->next;
		}
		varr[index].visited=1;
		printf("V%d",index);
		if(i!=v-1)
			printf("<-->");
		cost+=varr[index].minweight;
	}
	return cost;
}
int main(void)
{
	int item,v,i,s,cost=0;
	node* adj[20];
	vertex varr[20];
	printf("To find the Minimum Cost Spanning Tree of a graph: \n");
	printf("Enter the number of vertices in the graph : ");
	scanf("%d",&v);
	init_adj(adj,v);
	get_adjlist(adj,v);
	printf("Adjacency list for the entered graph:\n");
	disp_adjlist(adj,v);
	printf("Enter the source vertex: ");
	scanf("%d",&s);
	init_varr(varr,v,s);
	printf("Initialised vertices list:\n");
	disp_varr(varr,v);
	printf("Edges in the MCST are: \n");
	cost=primsmcst(adj,varr,v);
	printf("\nFinal vertices list:\n");
	disp_varr(varr,v);
	printf("\nMinimum Weight: %d\n",cost);
	return 0;
}


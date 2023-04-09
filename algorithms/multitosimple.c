

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

node* createnode(int item)
{
	node *temp=(node*)malloc(sizeof(node));
	temp->next=NULL;
	temp->data=item;
	return temp;
}

node* insert_at_end(node* start, int item)
{
	node *temp, *ptr;
	temp=createnode(item);
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
			printf("%d\t",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

void get_adjlist(node **adj,int v)
{
	int i,temp,j,vnum;
	for(i=0;i<v;i++)
	{
		printf("Enter the number of vertices connected to V%d: ",i);
		scanf("%d",&temp);
		for(j=0;j<temp;j++)
		{
			printf("Enter the vertex number : ");
			scanf("%d",&vnum);
			adj[i]=insert_at_end(adj[i],vnum);
		}
	}
}

void convert_to_simple(node **adj,node **tadj,int v)
{
	int i,item,last_item;
	node *temp;
	for(i=0;i<v;i++)
	{
		temp=adj[i];
		/*init*/
		item=temp->data;
		tadj[i]=insert_at_end(tadj[i],item);
		last_item=item;
		temp=temp->next;
		while(temp!=NULL)
		{
			if(temp->data != last_item && temp->data != i)
			{
				tadj[i]=insert_at_end(tadj[i],temp->data);
				last_item=temp->data;

			}
			temp=temp->next;
		}
	}
}

int main(void)
{
	int item,v,i;
	node *adj[20],*tadj[20];
	memset(adj,0,sizeof(adj));
	printf("To convert a multigraph to a simple graph:\n");
	printf("Enter the number of vertices in the multi-graph : ");
	scanf("%d",&v);
	get_adjlist(adj,v);
	memset(tadj,0,sizeof(tadj));
	printf("The adjacency list representation of G is :\n");
	disp_adjlist(adj,v);
	convert_to_simple(adj,tadj,v);
	printf("The equivalent simple graph of  G is :\n");
	disp_adjlist(tadj,v);
	return 0;
}


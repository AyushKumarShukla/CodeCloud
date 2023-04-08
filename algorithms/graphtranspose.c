
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

void transpose_adjlist(node **adj,node **tadj,int v)
{
	node *temp;
	int i,index;
	for(i=0;i<v;i++)
	{
		temp=adj[i];
		while(temp!=NULL)
		{
			index=temp->data;
			tadj[index]=insert_at_end(tadj[index],i);	
			temp=temp->next;
		}
	}
}

int main(void)
{
	int item,v,i;
	node *adj[20],*tadj[20];
	memsert(adj,0,sizeof(adj));
	printf("To find the transpose of a graph:\n");
	printf("Enter the number of vertices in the graph : ");
	scanf("%d",&v);
	get_adjlist(adj,v);
	memset(tadj,0,sizeof(tadj));
	printf("The adjacency list representation of G is :\n");\
	disp_adjlist(adj,v);
	transpose_adjlist(adj,tadj,v);
	printf("The adjacency list rep of GT is: \n");
	disp_adjlist(tadj,v);
	return 0;
}


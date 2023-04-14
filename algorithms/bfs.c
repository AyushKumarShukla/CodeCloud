#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct node
{
	int data;
	int color;
	int d;
	int pi;
	struct node *next;
}node;

node* createnode(int item)
{
	node *temp=(node*)malloc(sizeof(node));
	temp->next=NULL;
	temp->data=item;
	temp->color=0;
	temp->d=999;
	temp->pi=0;
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
			printf("%d %d %d %d\t",temp->data,temp->color,temp->d,temp->pi);
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

node* init_source(int vs)
{
	node *s;
	s=createnode(0);
	s->color=1;
	s->d=0;
	s->pi=0;
	return s;	
}

int main(void)
{
	int item,v,i,vs;
	node *s;
	node *adj[20];
	memset(adj,0,sizeof(adj));
	printf("To implement breadth first search in a graph:\n");
	printf("Enter the number of vertices in the simple graph : ");
	scanf("%d",&v);
	printf("Enter the source vertex number:");
	scanf("%d",&vs);
	get_adjlist(adj,v);
	s=init_source(vs);
	printf("The adjacency list representation of G is :\n");
	disp_adjlist(adj,v);
	printf("\nSource attributes: ");
	printf("%d %d %d %d\n",s->data,s->color,s->d,s->pi);
	return 0;
}


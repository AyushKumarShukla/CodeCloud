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

void displist(node* start)
{
	node* temp;
	temp=start;
	//printf("\n");
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void disp_adjlist(node** adj,int v)
{
	int i;
	for(i=0;i<v;i++)
	{
		printf("V%d: ",i);
		displist(adj[i]);
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

int main(void)
{
	int item,v,i;
	node* adj[20];
	printf("Enter the number of vertices in the graph : ");
	scanf("%d",&v);
	get_adjlist(adj,v);
	disp_adjlist(adj,v);
	return 0;
}


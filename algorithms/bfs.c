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

//this function initialises all nodes on demand
node* createnode(int item,int col,int dist,int pre)
{
	node *temp=(node*)malloc(sizeof(node));
	temp->next=NULL;
	temp->data=item;
	temp->color=col;
	temp->d=dist;
	temp->pi=pre;
	return temp;
}

node* insert_at_end(node* start, int item,int col,int dist,int pre)
{
	node *temp, *ptr;
	temp=createnode(item,col,dist,pre);
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
			adj[i]=insert_at_end(adj[i],vnum,0,999,-1);
		}
	}
}

node* delist(node *q)
{
	node* temp;
	temp=q->next;
	free(q);
	return temp;
}

void bfs(node **adj,int v,int vs)
{
	int current;
	node *queue=NULL,*trav=NULL;
	//initialising source
	queue=insert_at_end(queue,vs,1,0,-1);
	while(queue!=NULL)
	{
	        current=queue->data;
		trav=adj[current];
		while(trav!=NULL)
		{
			if(trav->color==0)
			{
				trav->color=1;
				trav->d= (queue->d) + 1;
				trav->pi=queue->data;
				//here,there should be a defined condition of when an element must be enqueued.
				queue=insert_at_end(queue,trav->data,trav->color,trav->d,trav->pi);
			}
				trav=trav->next;
		}
		queue=delist(queue);

	}
}

int main(void)
{
	int item,v,i,vs;
	node *adj[20];
	memset(adj,0,sizeof(adj));
	printf("To implement breadth first search in a graph:\n");
	printf("Enter the number of vertices in the simple graph : ");
	scanf("%d",&v);
	printf("Enter the source vertex number:");
	scanf("%d",&vs);
	get_adjlist(adj,v);
	printf("The adjacency list representation of G is :\n");
	disp_adjlist(adj,v);
	bfs(adj,v,vs);
	printf("After applying breadth first search: \n");
	disp_adjlist(adj,v);
	return 0;
}


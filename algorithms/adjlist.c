#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct node
{
	int data; //holds the vertex number
	struct node *next;
}node;

node* createnode(int item)
{
	node *temp=(node*)malloc(sizeof(node));
	temp->next=NULL;
	temp->data=item; //the data field holds the vertex number
	return temp;
}

node* insert_at_end(node* start, int item)
{
	node *temp=NULL, *ptr=NULL;
	temp=createnode(item);
	if(start==NULL) //if the adjacency list is empty
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
	node* temp=NULL;
	int i;
	for(i=0;i<v;i++)
	{
		printf("V%d: ",i);
		temp=adj[i]; 
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
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
//initialise the adjacency list pointers to NULL
void init_adj(node** adjlist,int v)
{
	int i;
	for(i=0;i<v;i++)
		adjlist[i]=NULL;		
}
//free the allocated nodes in the adjacency list
void free_adjlist(node** adjlist,int v)
{
	node* temp1=NULL;
        node* temp2=NULL;
        int i;
        for(i=0;i<v;i++)
        {
                temp1=adjlist[i];
                do
                {
                        if(temp1!=NULL)
                        {
                                temp2=temp1->next;
                                free(temp1);
                                temp1=temp2;
                        }
                }while(temp1!=NULL);
        }
}
int main(void)
{
	int item,v,i;
	node* adj[20];
	printf("Enter the number of vertices in the graph : ");
	scanf("%d",&v);
	init_adj(adj,v);
	get_adjlist(adj,v);
	disp_adjlist(adj,v);
	free_adjlist(adj,v);
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define DEFCOL 0
#define DEFD 999
#define DEFPI -1
#define SRCCOL 1
#define SRCD 0
#define VISITED 2
typedef struct node
{
	int data;
	int color;
	int d;
	int pi;
	struct node *next;
}node;

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
	node *temp=NULL, *ptr=NULL;
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
			printf("%d  %d  %d  %d  ",temp->data,temp->color,temp->d,temp->pi);
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
			adj[i]=insert_at_end(adj[i],vnum,DEFCOL,DEFD,DEFPI);
		}
	}
}
//to pop items off the stack
int pop(node **stack)  //using a pointer to a pointer to be able to set start of scope main to null
{
	node* temp=NULL;
	node* temp2=NULL;
	int val;
	temp=*stack;
	//since the dfs while loop handles empty stack, no checking has been included here
	if(temp->next==NULL) //if there is only one element
	{
		val=temp->data;
		free(temp);
		*stack=NULL;
	}
	else
	{
		while((temp->next)->next!=NULL)
			temp=temp->next;
		temp2=temp->next;
		val=temp2->data;
		free(temp2);
		temp->next=NULL;
	}
	return val;
	
}
//on paper, the nodes are global, changes made to one node are available to all other nodes, but in this 
//program,the adjacency list does not have the ability to sync changes made to a particular node number to all
//instances of that node in the adjacency list, therefore the extra list 'vertices' has been used to refer and
//update values of particular nodes.
void dfs(node **adj,node **vertices,int v,int vs)
{
	int current,index,vnode;
	node *stack=NULL,*trav=NULL;
	stack=insert_at_end(stack,vs,SRCCOL,SRCD,DEFPI);
	while(stack!=NULL)
	{
	        current=pop(&stack);
		trav=adj[current];
		while(trav!=NULL)
		{
			index=trav->data;
//should the condition be color==0 or color==0||color==1?
//if it is the former, nodes may not be visited due to its color being 1 which came for an older value of current while its adjacency list was being scanned and nodes were being marked as color=1
//what exactly should be the condition for pushing a node in the stack and changing its attributes wrt the incumbent current value....
			if(vertices[index]->color==0 || vertices[index]->color==1)
			{
				vertices[index]->color=1;
				vertices[index]->d=vertices[current]->d + 1;
				vertices[index]->pi=vertices[current]->data;
				stack=insert_at_end(stack,index,trav->color,trav->d,trav->pi);
			}
				trav=trav->next;
		}
		vertices[current]->color=VISITED;
	}
}
//this creates an array of node pointers with each index holding a node with number=index no, this list holds the intial values of all nodes and is updated as the dfs progresses,this is the result list
void get_vlist(node** vertices,int v,int vs)
{
	int i;
	for(i=0;i<v;i++)
	{
		if(i==vs)
			vertices[vs]=insert_at_end(vertices[vs],vs,SRCCOL,SRCD,DEFPI);
		else
			vertices[i]=insert_at_end(vertices[i],i,DEFCOL,DEFD,DEFPI);
	}

}

void free_lists(node** adjlist,node** vertices,int v)
{
	node* temp1=NULL;
	node* temp2=NULL;
	int i;
	for(i=0;i<v;i++)
	{
		free(vertices[i]);
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

void init_list_to_null(node** list,int num)
{
	int i;
	for(i=0;i<num;i++)
		list[i]=NULL;

}
int main(void)
{
	int item,v,i,vs,visited[20];
	node *adj[20];
	node *vertices[20];
	init_list_to_null(adj,20);
	init_list_to_null(vertices,20);
	memset(adj,0,sizeof(adj));
	printf("To implement Depth first search in a graph:\n");
	printf("Enter the number of vertices in the simple graph : ");
	scanf("%d",&v);
	if(v<1)
	{
		printf("Number of vertices cannot be less than 1\n");
		exit(1);
	}
	printf("Enter the source vertex number:");
	scanf("%d",&vs);
	if(vs<0 || vs > v)
	{
		printf("Invalid source vertex\n");
		exit(2);
	}
	get_vlist(vertices,v,vs);
	get_adjlist(adj,v);
	printf("The adjacency list representation of G is :\n");
	disp_adjlist(adj,v);
	dfs(adj,vertices,v,vs);
	printf("\nAfter applying depth first search: \n");
	printf("Vertices Attribute List Is:\n");
	printf("VNUM COL DIST PRE\n");
	disp_adjlist(vertices,v);
	free_lists(adj,vertices,v);
	return 0;
}


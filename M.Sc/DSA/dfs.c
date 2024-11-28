/*Implementation: Unweighted Undirected Graph
Author: Ayush Kumar Shukla
Date: 13-11-24 --> v1.0
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 20

typedef struct{
	int values[MAX];
	int top;
}Stack;

void initStack(Stack *s)
{
	s->top = -1;
}

bool isEmpty(Stack *s)
{
	return s->top == -1;
}

void push(Stack *s,int arg)
{
	if(s->top < MAX-1)
	{
		(s->top) = (s->top) + 1;
		s->values[(s->top)] = arg;
	}
	else
		printf("Stack Full");
}

int pop(Stack *s)
{
	int ret;
	if (!isEmpty(s))
	{
		ret = s->values[s->top];
		s->top = s->top - 1;
	}
	else
		printf("Stack Is Already Empty");
	return ret;
}

void dispStack(Stack *s)
{
	int i;
	for(i=0;i<=(s->top);i++)
		printf("%d\t",s->values[i]);
	
}
void dfs(int graph[MAX][MAX],int start,int vcount)
{
	int current,i,j;
	Stack stack;
	bool visited[MAX] = {false};
    int parent[MAX];
	
    for(i=0;i<vcount;i++)
        parent[i] = -1;

	initStack(&stack);
	push(&stack,start);
	
	while(!isEmpty(&stack))
	{
		current = pop(&stack);
		if(!visited[current])
		{
			printf("%d\t",current);
			visited[current] = true;
		
		
		    for(i=vcount-1;i>=0;i--)
		    {
			    if(graph[current][i] == 1 && !visited[i])
                {
				    push(&stack,i);
                    parent[i] = current;
                }
		    }
        }
	}

    //DFS tree edges
    printf("\nDFS Tree Edges: \n");
    printf("S<-->D\n");
    for(i=0;i<vcount;i++)
        if(parent[i] != -1)
            printf("%d<-->%d\n",parent[i],i);
}


void inputMatrix(int(*graph)[MAX],int ecount)
{
	int i,j;
    int source,end;
    for(i=0;i<ecount;i++)
    {
        printf("Enter incident vertices of edge %d:\t",i+1);
        scanf("%d %d",&source,&end);
        graph[source][end] = 1;
        graph[end][source] = 1;
    }
}

void showMatrix(int(*graph)[MAX],int vcount)
{
	int i,j;
	for(i=0;i<vcount;i++)
	{
		for(j=0;j<vcount;j++)
		{
			printf("%d\t",graph[i][j]);		
		}
		printf("\n");
	}
}

void initGraph(int(*graph)[MAX],int vcount)
{
    int i,j;
    for(i=0;i<vcount;i++)
        for(j=0;j<vcount;j++)
            graph[i][j] = 0;
}

int main(void)
{
	int vcount,ecount,i,j,start;
	int graph[MAX][MAX];
    

	printf("Enter the number of vertices in the graph: ");
	scanf("%d",&vcount);

	printf("Enter the number of edges in the graph: ");
	scanf("%d",&ecount);
    
    initGraph(graph,vcount);

	printf("Enter the graph: \n");
	inputMatrix(graph,ecount);

    printf("Enter the start vertex for DFS traversal: ");
    scanf("%d",&start);
	
	printf("Entered Adjacency Matrix:\n");
	showMatrix(graph,vcount);
	
	printf("DFS Traversal:\t");
	dfs(graph,start,vcount);
    printf("\n");
    return 0;
}

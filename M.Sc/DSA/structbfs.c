#include<stdio.h>
#include<stdbool.h>
#define MAX 20

typedef struct{
	int values[MAX];
	int rear;
	int front;
}Queue;

typedef struct{
	int values[MAX][MAX];
	int vcount;
	int ecount;
}Graph;

void initQueue(Queue* queue)
{
    queue->front = -1;
    queue->rear = -1;
}

void Enqueue(Queue* queue,int arg)
{
    if(queue->rear >= MAX - 1)
        printf("Queue Full");
    else
    {
        if(queue->front == -1)
            queue->front = 0;

        queue->rear = queue->rear + 1;
        queue->values[queue->rear] = arg;
    }

}

int Dequeue(Queue* queue)
{
    int ret;
    if(queue->front == -1 || queue->front > queue->rear)
    {
        printf("Queue empty");
        return -1;
    }
    else
    {
        ret = queue->values[queue->front];
        queue->front = queue->front + 1;
        if(queue->front > queue->rear)
            initQueue(queue);
        return ret;
    }
}

void bfs(Graph* graph)
{
    int i,j,ret;
    bool visited[MAX] = {false};
    Queue queue;
    initQueue(&queue);

    for(i=0;i<graph->vcount;i++)
    {
        if(!visited[i])
        {
            Enqueue(&queue,i);
            visited[i] = true;

            while(queue.front != -1)
            {
                ret = Dequeue(&queue);
                printf("%d\t",ret);

                for(j=0;j<graph->vcount;j++)
                {
                    if(graph->values[ret][j] == 1 && !visited[j])
                    {
                        Enqueue(&queue,j);
                        visited[j] = true;
                    }
                }
            }
        }
    }
}


void initGraph(Graph* graph,int vcount,int ecount)
{
	int i,j;
	graph->vcount = vcount;
	graph->ecount = ecount;
	
	for(i=0;i<vcount;i++)
		for(j=0;j<vcount;j++)
			graph->values[i][j] = 0;
}

void inputGraph(Graph* graph)
{
	int i;
	int source,dest;
	for(i=0;i<graph->ecount;i++)
	{
		printf("Enter the vertices of edge %d: ",i+1);
		scanf("%d %d",&source,&dest);
		graph->values[source][dest] = 1;
		graph->values[dest][source] = 1;
	}
}

void showGraph(Graph* graph)
{
	int i,j;
	for(i=0;i<graph->vcount;i++)
	{
		for(j=0;j<graph->vcount;j++)
			printf("%d\t",graph->values[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int vcount,ecount;
	Graph graph;
	
	printf("Enter the number of vertices: ");
	scanf("%d",&vcount);
	printf("Enter the number of edges: ");
	scanf("%d",&ecount);
	
	initGraph(&graph,vcount,ecount);
	inputGraph(&graph);
    printf("Generated Adjacency Matrix:\n");
	showGraph(&graph);
    printf("\n\nBFS TRAVERSAL:\t");
    bfs(&graph);
    printf("\n");
	return 0;
}

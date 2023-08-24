#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<stdbool.h>
#define INF (1.0/0.0) //USE WITH EXTREME CAUTION: GENERATES -infinity value NOT +infinity value
#define ROOT -1
#define ZEROWEIGHT 0
#define MAX 999
void init_lists(int* key,bool* MSTset,int v)
{
	int i;
	for(i=0;i<v;i++)
	{
		key[i]=INT_MAX;
		MSTset[i]=false;
	}
}
int extractmin(int* key, bool* MSTset,int v)
{
	int minval=INT_MAX,minindex,i;
	for(i=0;i<v;i++)
	{
		if(MSTset[i]==false && key[i]<minval)
		{
			minval=key[i];
			minindex=i;
		}
	}
	return minindex;
}
void primsMST(int(*graph)[20],int* parent,int* key,bool* MSTset,int v)
{
	int count,i,u;
	for(count=0;count<v-1;count++)//count<v-1
	{
		u=extractmin(key,MSTset,v);
		MSTset[u]=true; //selected source vertex marked as visited
		//start scanning adjacent vertices
		for(i=0;i<v;i++)
		{
			if(graph[u][i]!=MAX && MSTset[i]==false && graph[u][i]<key[i])
			{
				parent[i]=u;
				key[i]=graph[u][i];
			}
		}
	}
}
void getmatrix(int(*graph)[20],int v)
{
	int i,j,inp;
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
		{
			scanf("%d",&inp);
			if(inp==MAX)
				graph[i][j]=MAX;
			else
				graph[i][j]=inp;
		}
}
void dispmatrix(int(*graph)[20],int v)
{
	int i,j;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
			printf("%d\t",graph[i][j]);
		printf("\n");
	}
}
void dispMST(int(*graph)[20],int* parent, int v,int source)
{
	int i;
	for(i=0;i<v;i++)
	{
		if(i==source)
			continue;
		printf("%d<-->%d\t%d\n",parent[i],i,graph[i][parent[i]]);
	}
}
int main(void)
{
	int graph[20][20],parent[20],key[20],v,i,source;
	bool MSTset[20];
	printf("Enter the number of vertices in the graph: ");
	scanf("%d",&v);
	init_lists(key,MSTset,v);
	printf("Enter the source vertex: ");
	scanf("%d",&source);
	parent[source]=ROOT;
	key[source]=ZEROWEIGHT;
	printf("Enter the adjacency matrix: \n");
	getmatrix(graph,v);
	printf("Entered Adjacency Matrix: \n");
	dispmatrix(graph,v);
	primsMST(graph,parent,key,MSTset,v);
	printf("Edges in the MST: \n");
	printf("Edge\tWeight\n");
	dispMST(graph,parent,v,source);
	return 0;
}

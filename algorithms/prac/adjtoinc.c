#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<stdbool.h>
#define V 6
#define E 9
void getadj(int(*adj)[V],int v)
{
	int i,j,inp;
	for(i=0;i<v;i++)
		for(j=i;j<v;j++)
		{
			scanf("%d",&inp);
			adj[i][j]=inp;
			adj[j][i]=inp;
		}
}

void dispadj(int(*adj)[V],int v)
{
	int i,j,inp;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
			printf("%d\t",adj[i][j]);
		printf("\n");
	}
}

void adjtoinc(int(*adj)[V],bool(*inc)[V],int v,int e)
{
	int i,j,k=0;
	for(i=0;i<v;i++)
	{
		for(j=i;j<v;j++)
		{
			if(adj[i][j]!=0 && adj[i][j]!=9)
			{
				inc[i][k]=true;
				inc[j][k]=true;
				k++;
			}
		}
		
	}
}
void dispinc(bool(*inc)[V],int v,int e)
{
	int i,j;
	for(i=0;i<v;i++)
	{
		for(j=0;j<e;j++)
			printf("%d\t",inc[i][j]);
		printf("\n");
	}
}
int main(void)
{
	int v,e;
	bool inc[V][V];
	int i,j;
	for(i=0;i<20;i++)
		for(j=0;j<20;j++)
			inc[i][j]=false;
	int adj[V][V]= { {0,1,1,9,9,9},
		{1,0,3,9,9,4},
		{1,3,0,4,5,9},
		{9,9,4,0,2,1},
		{9,9,5,2,0,1},
		{9,4,9,1,1,0}};
	//getadj(adj,v);
	printf("Entered adjacency matrix of the undirected graph:\n");
	dispadj(adj,V);
	adjtoinc(adj,inc,V,E);
	printf("Generated Incidence Matrix\n");
	dispinc(inc,V,E);
	
}

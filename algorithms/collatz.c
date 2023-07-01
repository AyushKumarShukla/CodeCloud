#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<unistd.h>
void collatz(int x)
{
	int temp=x;
	do
	{
		if(x%2==0)
			x=(x/2);
		else
			x=3*x+1;
		printf("INTER:%d\n",x);
	}while(x!=1);
	printf("True For x=\t\t%d\n",temp);
	return;
}

int main(void)
{
	int i;
	for(i=-1;i>-INT_MAX;i--)
		collatz(i);
}

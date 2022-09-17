#include<stdio.h>
#include<stdlib.h>


void getmat(int(*arr)[20],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			scanf("%d",&arr[i][j]);
}
void dispmat(int(*arr)[20],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			printf("%d\t",arr[i][j]);
		printf("\n");
	}
}

void isdiagmat(int(*arr)[20],int row,int col)
{
	  int i,j;
	  for(i=0;i<row;i++)
	  	for(j=0;j<col;j++)
	  		{
	  			if(i!=j)
	  				if(arr[i][j]!=0)
	  				{
	  					printf("\nEntered Matrix Is Not A Diagonal Matrix\n");
	  					exit(1);
	  				}
	  		}
	 printf("\nEntered Matrix Is A Diagonal Matrix");
}

void genlist(int(*arr)[20],int *list,int row,int col)
{
	int i,j,k=0;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			if(i==j)
			{
				list[k]=arr[i][j];
				k++;
			}
}

void displist(int* list , int max)
{
	int i;
	for(i=0;i<max;i++)
		printf("%d ",list[i]);
}

void recons(int*list,int max)
{
	int i,j;
	for(i=0;i<max;i++)
	{
		for(j=0;j<max;j++)
			{
				if(i==j)
					printf("%d\t",list[i]);
				else
					printf("0\t");
			}
		printf("\n");
	}
}


int main(void)
{
	int arr[20][20],*list,row,col;
	while(1)
	{
		printf("Enter the number of rows needed: ");
		scanf("%d",&row);
		printf("Enter the number of columns needed: ");
		scanf("%d",&col);
		if(row==col)
			break;
		else
			printf("Input Matrix Is Not A Square Matrix....Please Try Again");
	}
	printf("Enter %d elements of the matrix: \n",row*col);
	getmat(arr,row,col);
	printf("\nEntered Matrix: \n");
	dispmat(arr,row,col);
	isdiagmat(arr,row,col);
	list=(int*)calloc(row,sizeof(int));
	genlist(arr,list,row,col);
	printf("\nGenerated List: ");
	displist(list,row);
	printf("\nReconstructed Matrix:\n");
	recons(list,row);
	return 0;
}

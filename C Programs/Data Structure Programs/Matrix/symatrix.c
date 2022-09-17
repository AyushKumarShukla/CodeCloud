#include<stdio.h>
#include<stdlib.h>

void validate(int row,int col)
{
	if(row!=col)
	{
		printf("Triangular Matrix Must Be A Square Matrix!\nPlease Try Again\n");
		exit(1);
	}
	return;
}

void prompt(void)
{
	int ch;
	while(1)
	{
		printf("Press 1 to continue OR press 0 to exit");
		scanf("%d",&ch);
		if(ch==1)
			return;
		else if(ch==0)
			exit(1);
		printf("\nInvalid Input, Please Try Again\n");
	}
}

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

	

void makelist(int*list,int(*arr)[20],int row,int col)
{
	int i,j,k=0;

	for(i=0;i<row;i++)
		for(j=i;j<col;j++)
		{
			list[k]=arr[i][j];
			k++;
		}
}

void displist(int*arr,int size)
{
	int i;
	for(i=0;i<size;i++)
		printf("%d ",arr[i]);
}

void issymatrix(int(*arr)[20],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			if(i!=j)
			{
				if(arr[i][j]!=arr[j][i])
				{
					printf("Entered matrix is not symmetric");
					exit(0);
				}
			}
}

int main(void)
{ 
	int ch,row,col,arr[20][20],*list,size;
	printf("For a symmetric matrix: \n");
	printf("Enter Number Of Rows: ");
	scanf("%d",&row);
	printf("Enter Number Of Columns: ");
	scanf("%d",&col);
	validate(row,col);
	printf("\nEnter %d elements of the matrix: \n",row*col);
	getmat(arr,row,col);
	printf("\nEntered Matrix: \n");
	dispmat(arr,row,col);
	issymatrix(arr,row,col);
	puts("\nEntered Matrix Is Symmetric");
	size=(row*(row+1))/2;
	list=(int*)malloc(size*sizeof(int));
	makelist(list,arr,row,col);
	printf("\nGenerated List: ");
	displist(list,size);
	return 0;
}

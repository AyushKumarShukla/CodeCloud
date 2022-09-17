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

int nonzero(int(*arr)[20],int row,int col)
{
	int i,j,cnt=0;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			if(arr[i][j]!=0)
				cnt++;
	return cnt;
}

void issparse(int(*arr)[20],int row,int col)
{
	int cnt,limit,total=row*col;
	cnt=nonzero(arr,row,col);
	limit=total/3;
	if(cnt<limit)
	{
		printf("Input matrix is a sparse matrix\n");
		return;
	}
	else
	{
		printf("Input matrix is not a sparse matrix\n");
		exit(0);
	}
}

void makesparsemat(int(*arr)[20],int(*list)[20],int row,int col)
{
	int i,j,k=0;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			if(arr[i][j]!=0)
			{
				list[0][k]=i;
				list[1][k]=j;
				list[2][k]=arr[i][j];
				k++;
			}
}

void dispsparse(int(*list)[20],int cnt)
{
	int i,j;
	for(i=0;i<3;i++)
	{
		if(i==0)
			printf("ROW\t");
		else if(i==1)
			printf("COLUMN\t");
		else
			printf("ELEMENT\t");
		for(j=0;j<cnt;j++)
			printf("%d\t",list[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int arr[20][20],list[3][20],row,col,cnt;
	printf("Enter the number of rows: ");
	scanf("%d",&row);
	printf("Enter the number of columns: ");
	scanf("%d",&col);
	printf("Enter %d elements of the matrix: \n",row*col);
	getmat(arr,row,col);
	printf("Entered matrix: \n");
	dispmat(arr,row,col);
	issparse(arr,row,col);
	makesparsemat(arr,list,row,col);
	cnt=nonzero(arr,row,col);
	printf("\nElements of sparse matrix: \n");
	dispsparse(list,cnt);
	return 0;
}

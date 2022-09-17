#include<stdio.h>
#include<stdlib.h>

typedef struct spmat
{
	int row;
	int col;
	int ele;
}spmat;

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

void makesparsearr(int(*arr)[20],spmat *list,int row,int col)
{
	int i,j,k=0;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			if(arr[i][j]!=0)
			{
				list[k].row=i;
				list[k].col=j;
				list[k].ele=arr[i][j];
				k++;
			}
}

void dispsparse(spmat *list,int cnt)
{
	int i=0;
	printf("ROW\tCOLUMN\tELEMENT\n");
	for(i=0;i<cnt;i++)
	{
		printf("%d\t%d\t%d\n",list[i].row,list[i].col,list[i].ele);
	}
}

void disparr(spmat *arr,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d %d %d ",arr[i].row,arr[i].col,arr[i].ele);
	}
}

int main(void)
{
	int arr[20][20],row,col,cnt;
	spmat *list;
	printf("Enter the number of rows: ");
	scanf("%d",&row);
	printf("Enter the number of columns: ");
	scanf("%d",&col);
	printf("Enter %d elements of the matrix: \n",row*col);
	getmat(arr,row,col);
	printf("Entered matrix: \n");
	dispmat(arr,row,col);
	issparse(arr,row,col);
	cnt=nonzero(arr,row,col);
	list=(spmat*)malloc(cnt*sizeof(spmat));
	makesparsearr(arr,list,row,col);
	printf("\nElements of the 1-D array: ");
	disparr(list,cnt);
	printf("\nSparse matrix constructed from 1-D array: \n");
	dispsparse(list,cnt);
	return 0;
}
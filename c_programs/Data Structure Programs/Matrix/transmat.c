/*WAP in C to find the transpose of a matrix*/

#include<stdio.h>
#include<stdlib.h>
//function to take input in a matrix
void getmatrix(int (*arr)[20],int row,int column)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
			scanf("%d",&arr[i][j]);
	}
}
//function to display a matrix
void dispmatrix(int (*arr)[20],int row,int column)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
			printf("%d\t",arr[i][j]);
		printf("\n");
	}
}
//function for interchanging variable values
void swap(int*a,int*b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}
//function for input validation
void validate(int row,int col)
{
    if(row<1 || col<1)
    {
        printf("Invalid Dimensions\nPlease Enter a Valid Dimension");
        exit(1);
    }
}


void trans(int(*arr)[20],int row,int col)
{
	int i,j,mid;
	mid=0;
	while(mid<row) //traversing the square part of the input matrix
	{
		for(i=mid+1;i<row;i++) 
			swap(&arr[mid][i],&arr[i][mid]);
		mid++;
	}
	if(row!=col) //if input matrix is not a square matrix
	{
		j=row;
		while(j<col)//traversing the non square part of the matrix
		{
			for(i=0;i<row;i++)
				swap(&arr[i][j],&arr[j][i]);
			j++;
		}
	}
}

int main(void)
{
	int arr[20][20],row,col;
	printf("Enter the number of rows needed: ");
	scanf("%d",&row);
	printf("Enter the number of columns needed: ");
	scanf("%d",&col);
    validate(row,col); //input validation
	printf("Enter %d elements of the matrix: \n",row*col);
	getmatrix(arr,row,col);
	printf("\nElements of the matrix: \n");
	dispmatrix(arr,row,col); //displaying input matrix
	trans(arr,row,col);
    printf("\nTranspose: \n");
	dispmatrix(arr,col,row);//displaying transposed input matrix
	return 0;
}
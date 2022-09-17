#include<stdio.h>
#include<stdlib.h>

void multiply(int(*arrone)[20],int(*arrtwo)[20],int(*res)[20],int rowone,int colone,int rowtwo,int coltwo)
{
	int i,j,cnt,sum=0;
	for(i=0;i<rowone;i++)
	{
		for(cnt=0;cnt<coltwo;cnt++)
		{
			sum=0;
			for(j=0;j<rowtwo;j++)
			{
				sum=sum+(arrone[i][j]*arrtwo[j][cnt]);
			}
			res[i][cnt]=sum;
		}
	}
}
void dispres(int(*res)[20],int rowone,int coltwo)
{
	int i,j;
	for(i=0;i<rowone;i++)
	{
		for(j=0;j<coltwo;j++)
			printf("%d\t",res[i][j]);
		printf("\n");
	}
}

void getmat(int(*arr)[20],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			scanf("%d",&arr[i][j]);
}

void validate(int colone,int rowtwo)
{
	if(colone!=rowtwo)
	{
		printf("Given matrices cannot be multiplied....Please try again");
		exit(0);
	}
}
int main(void)
{
	int arrone[20][20],arrtwo[20][20],res[20][20],rowone,colone,rowtwo,coltwo;
	printf("To multiply two matrices\n");
	printf("Enter the number of rows of the first matrix: ");
	scanf("%d",&rowone);
	printf("Enter the number of columns of the first matrix: ");
	scanf("%d",&colone);
	printf("Enter the number of rows of the second matrix: ");
	scanf("%d",&rowtwo);
	printf("Enter the number of columns of the second matrix: ");
	scanf("%d",&coltwo);
	//input validation
	validate(colone,rowtwo);
	printf("Enter the elements of the first matrix: \n");
	getmat(arrone,rowone,colone);
	printf("Enter the elements of the second matrix: \n");
	getmat(arrtwo,rowtwo,coltwo);
	multiply(arrone,arrtwo,res,rowone,colone,rowtwo,coltwo);
	printf("\nPRODUCT OF THE TWO MATRICES: \n");
	dispres(res,rowone,coltwo);
	return 0;
}

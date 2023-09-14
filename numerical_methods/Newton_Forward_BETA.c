#include<stdio.h>
#include<stdlib.h>
/*Beta Version*/

void getarray(float(*arr)[20],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
		for(j=col;j<col+1;j++)
			scanf("%f",&arr[i][j]);
}

void disparray(float(*arr)[20],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			printf("%.2f ",arr[i][j]);
		printf("\n");
	}
}

void createtable(float(*arr)[20],int row_count)
{
	int i,j,col=2,count=1;
	while(count<row_count)
	{
		for(i=0;i<row_count;i++)
		{
			arr[i][col]=arr[i+1][col-1]-arr[i][col-1];
		}
		col++;
		count++;
	}
}

float fact(float num)
{
	if(num==1)
		return 1;
	else
		return num*fact(num-1);
}

float calc(float(*arr)[20],int row,float find,float phase)
{
	int i,j;
	float temp=0,factor=0;
	for(i=0;i<row-1;i++)
	{
		for(j=-1;j<i;j++)
		{
			factor=factor+phase;
			phase--;
		}
		printf("\nPHASE %d:%f",i+1,factor);
		temp=(temp+factor*(arr[0][i+2]))/fact(i+2);
		printf("\nTERM %d:%f",i+1,temp);
	}
	temp=temp+arr[0][1];
	printf("ANSWER:%.2f",temp);
}

int main(void)
{
	int terms,i,j;
	float mat[20][20],val,result,phase,height;;
	printf("Enter the number of terms: ");
	scanf("%d",&terms);
	printf("Enter x in F(x): ");
	scanf("%f",&val);
	printf("Enter the values of x: ");
	getarray(mat,terms,0);
	printf("Entered Values of x: \n");
	disparray(mat,terms,terms+1);
	printf("\nEnter the values of y: ");
	getarray(mat,terms,1);
	printf("Entered Values of y: \n");
	disparray(mat,terms,terms+1);
	createtable(mat,terms);
	printf("Forward Difference Table: \n");
	disparray(mat,terms,terms+1);
	printf("\n");
	height=mat[1][0]-mat[0][0];
	phase=(val-mat[0][0])/height;
	calc(mat,terms,val,phase);
}

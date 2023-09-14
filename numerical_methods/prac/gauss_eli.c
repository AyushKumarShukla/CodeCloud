#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
19-02-23
PROGRAM IDEA:
1.Create a row operation function that takes a source row number and a destination row number, and performs
the required row operation.
2. Traverse the matrix and make the lower left triangle elements zero
3. Perform case-specific back substitution for convenience.*/

void get_mat(double (*matrix)[20],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			scanf("%lf",&matrix[i][j]);
}

void disp_mat(double (*matrix)[20],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			printf("%.2lf ",matrix[i][j]);
		printf("\n");
	}
}

void rowop(double (*mat)[20],int row_s,double mult,int row_d,int len)
{
	int j;
	for(j=0;j<len+1;j++)
		mat[row_d][j]=mat[row_d][j]-(mult*mat[row_s][j]);
}

void gauss_eli(double (*mat)[20],int row)
{
	int i,j;
	double mult;
	for(i=0;i<row;i++)
	{
		for(j=0;j<row;j++)
		{
			if(j<i)
			{
				mult=mat[i][j]/mat[j][j];
				rowop(mat,j,mult,i,row); // i represents row to be changed, j represents source row
			}
		}
	}
}

void backsub(double (*mat)[20],int len)
{
	double x1,x2,x3;
	x3=mat[2][3]/mat[2][2];
	x2=(mat[1][3]-mat[1][2]*x3)/mat[1][1];
	x1=(mat[0][3]-mat[0][2]*x3-mat[0][1]*x2)/mat[0][0];
	printf("The roots are : \nx1:%lf\nx2:%lf\nx3:%lf",x1,x2,x3);
}

int main(void)
{
	double matrix[20][20];
	int row;
	printf("To solve a system of linear equations using Gauss Elimination Method:\n");
	printf("Enter the number of equations: ");
	scanf("%d",&row);
	printf("Enter the %dx%d augmented matrix: \n",row,row+1);
	get_mat(matrix,row,row+1);
	printf("Entered matrix: \n");
	disp_mat(matrix,row,row+1);
	gauss_eli(matrix,row);
	printf("After applying Gauss Elimination: \n");
	disp_mat(matrix,row,row+1);
	printf("After applying BackSubstitution \n");
	backsub(matrix,row);
	return 0;
}


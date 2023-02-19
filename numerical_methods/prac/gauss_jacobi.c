#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define error 1e-10
/*
DATE:18-02-23
Program Idea:
TO CHECK DIAGONAL DOMINANCE
TO MAKE DIAGONALLY DOMINANT:
1. Traverse though the whole column of the diagonal element, and check if the abs value of any other
   element in that column has a larger value than the diagonal element.
   	CAUTION: Check only on the coefficient matrix
2. If so, the matrix is not diagonally dominant, find the element that is the largest in that particular row
   and swap it in the row position of the diagonal element.
3. Here, column counters stay fixed while row counter increase in one nested iteration, kinda column major
4.    DONT EVER FORGET THE FABS(), WE NEED ABSOLUTE VAUES!!!!!!
NOTE: Swapping to make things diagonally dominant is not ideal since it changes the order of the equations,
which manyatimes can change the meaning of the system. The order matters in some system such as electrical
analysis etc. It works for simpler systems, but swapping is not a foolproof apporoach.
Thus ChatGPT, preferred changing the equations, by a factor so that they get altered, become diagonally 
dominant, and approximately have the same meaning as the original equation while retaining the order.
This Works
Just For Now
If You're Building An App For The Tomorrow
It Needs To Change....
DATE:19-02-23
GENERAL PURPOSE GAUSS JACOBI METHOD
	Using the given system of linear equations, we can find equations that give values for each x, the 
	equation will contain the variables x and their coefficients, the coeffiecients can be obtained from
	the augmented matrix, and the equations can be represented in the program, new and old values for each
	x are stored to compare their values and exit when they reach a threshold range.
*/
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

void swap_rows(double (*matrix)[20],int row,int j,int max_loc)
{
	int k;
	double temp;
	for(k=0;k<row+1;k++) // swapping the ith row and max_loc row to establish diagonal dominance
	{
		temp=matrix[j][k];
		matrix[j][k]=matrix[max_loc][k];
		matrix[max_loc][k]=temp;
	}
}

int check_diag_dom(double (*matrix)[20],int row)
{
	int i,j;
	double sum=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<row;j++)
			if(i!=j)
			{
				sum=0;
				sum=sum+fabs(matrix[i][j]);
			}
		if(sum>fabs(matrix[i][i]))
		{
			printf("The given system is not diagonally dominant\n");
			return 1;
		}

	}
	return 0;
}

void make_diag_dom(double (*matrix)[20],int row)
{
	int i,j;
	double max,max_loc;
	for(j=0;j<row;j++)//column counter
	{
		max=matrix[j][j];
		max_loc=j;
		for(i=0;i<row;i++)//row counter
		{
			if(i!=j && fabs(matrix[i][j])>fabs(max))
			{
				max=matrix[i][j];
				max_loc=i;
			}
		}
		if(max_loc != j)
		{
			swap_rows(matrix,row,j,max_loc);
		}
	}
}

void gauss_jacobi_method(double (*mat)[20],int row)
{
	double x1=0,x2=0,x3=0,x1_new,x2_new,x3_new;
	while(1)
	{
		x1_new=(mat[0][3]-mat[0][1]*x2-mat[0][2]*x3)/mat[0][0];
		x2_new=(mat[1][3]-mat[1][0]*x1-mat[1][2]*x3)/mat[1][1];
		x3_new=(mat[2][3]-mat[2][0]*x1-mat[2][1]*x2)/mat[2][2];
		if(fabs(x1-x1_new)<error && fabs(x2-x2_new)<error && fabs(x3-x3_new)<error)
			break;
		else
		{
			x1=x1_new;
			x2=x2_new;
			x3=x3_new;
		}
	}
	printf("Roots are:\nx1=%lf\nx2=%lf\nx3=%lf",x1_new,x2_new,x3_new);
}

int main(void)
{
	double matrix[20][20];
	int row;
	printf("To solve a system of linear equations using Gauss Jacobi Method:\n");
	printf("Enter the number of equations: ");
	scanf("%d",&row);
	printf("Enter the %dx%d augmented matrix: \n",row,row+1);
	get_mat(matrix,row,row+1);
	printf("Entered matrix: \n");
	disp_mat(matrix,row,row+1);
	if(check_diag_dom(matrix,row))
	{
		make_diag_dom(matrix,row);
		printf("The matrix made diagonally dominant is :\n");
		disp_mat(matrix,row,row+1);
	}
	else
		printf("The Entered System is diagonally dominant\n");
	gauss_jacobi_method(matrix,row);

}


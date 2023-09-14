/*C program to implement Gauss Seidel method*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void matinit(float(*matrix)[20],int ord)
{
    int i,j;
    for(i=0;i<ord;i++)
        for(j=0;j<(ord+1);j++)
            scanf("%f",&matrix[i][j]);
}

void matdisp(float(*matrix)[20],int ord)
{
    int i,j;
    for(i=0;i<ord;i++)
    {
        for(j=0;j<(ord+1);j++)
            printf("%.3f ",matrix[i][j]);
        printf("\n");
    }
}

void init_var_arr(float(*matrix)[20],float *arr,int ord)
{
    int i;
    for(i=0;i<ord;i++)
        arr[i]=((matrix[i][ord])/(matrix[i][i]));
}

void disparr(float *arr,int ord)
{
    int i;
    for(i=0;i<ord;i++)
        printf("X%d = %.3f\n",i,arr[i]);
}
void Gauss_Jacobi(float (*matrix)[20],int ord)
{
    int limit,count=0,i,j;
    float *var_arr,temp=0;

    var_arr=(float*)malloc((ord)*sizeof(float));
    init_var_arr(matrix,var_arr,ord);
    printf("\nInitial Guess Values are: \n");		 
    disparr(var_arr,ord);//displays the initial values of var_arr
    printf("\nEnter the number of iterations: ");
    scanf("%d",&limit);

    while(count!=limit)
    {
        for(i=0;i<ord;i++)
        {
            for(j=0;j<ord;j++)
            {
                if(j==i)
                    continue;
                else
                    temp=temp+(matrix[i][j]*var_arr[j]);
            }
            temp=((matrix[i][ord])-(temp))/matrix[i][i];
            var_arr[i]=temp;
            temp=0;
        }
        count++;
    }
    printf("The Approximated Values Upto %d Iterations Are: \n",limit);
    disparr(var_arr,ord);
    printf("\n");
}
void check_dd(float (*arr)[20], int ord)
{
	int i,j;
	float sum;
	for(i=0;i<ord;i++)
	{
		sum=0;
		for(j=0;j<ord;j++)
		{
			if(i==j)
				continue;
			sum=sum+fabs(arr[i][j]);
		}
		if(fabs(sum)>fabs(arr[i][i]))
		{
			printf("The given system of equations is not diagonally dominant\n");
			printf("Please enter a diagonally dominant system of equations\n");
			exit(1);
		}
	}
}

int main(void)
{
    int ord;
    float matrix[20][20];
    printf("To solve a system of linear equations by Gauss-Seidel Iteration Method:\n");
    printf("Enter the number of equations: ");
    scanf("%d",&ord);
    printf("\nEnter %d elements of the augmented matrix:\n",ord*(ord+1));
    matinit(matrix,ord);
    check_dd(matrix,ord);
    printf("\n%d elements of the matrix are: \n",ord*(ord+1));
    matdisp(matrix,ord);
    Gauss_Jacobi(matrix,ord);
    return 0;
    
}

/*C program to implement Gauss Jacobi method*/
#include<stdio.h>
#include<stdlib.h>

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
        printf("%.3f ",arr[i]);
}

void Gauss_Jacobi(float (*matrix)[20],int ord)
{
    int limit,count=0,i,j;
    float *var_arr,temp=0;

    var_arr=(float*)malloc((ord)*sizeof(float));
    init_var_arr(matrix,var_arr,ord);

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
    printf("The Approximated Values Upto A Order Of %d Are: ",limit);
    disparr(var_arr,ord);
}

int main(void)
{
    int ord;
    float matrix[20][20];
    printf("Enter the number of equations: ");
    scanf("%d",&ord);
    printf("\nEnter %d elements of the matrix:\n",ord*(ord+1));
    matinit(matrix,ord);
    printf("\n%d elements of the matrix are: \n",ord*(ord+1));
    matdisp(matrix,ord);
    Gauss_Jacobi(matrix,ord);

}
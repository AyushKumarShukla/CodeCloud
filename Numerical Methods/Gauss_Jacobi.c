/*C program to implement Gauss Jacobi method*/
#include<stdio.h>
#include<stdlib.h>

void matinit(float(*matrix)[20],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            scanf("%f",&matrix[i][j]);
}

void matdisp(float(*matrix)[20],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            printf("%.2f ",matrix[i][j]);
        printf("\n");
    }
}

void init_var_arr(float(*matrix)[20],float *arr,int row,int col)
{
    int i;
    for(i=0;i<row;i++)
        arr[i]=((matrix[i][col-1])/(matrix[i][i]));
}

void disparr(float *arr,int row)
{
    int i;
    for(i=0;i<row;i++)
        printf("%.20f ",arr[i]);
}

void Gauss_Jacobi(float (*matrix)[20],int row,int col)
{
    int limit,count=0,i,j;
    float *var_arr,temp=0;

    var_arr=(float*)malloc((row)*sizeof(float));
    init_var_arr(matrix,var_arr,row,col);

    disparr(var_arr,row);
    printf("\nEnter the number of iterations: ");
    scanf("%d",&limit);

    while(count!=limit)
    {
        for(i=0;i<row;i++)
        {
            for(j=0;j<row;j++)
            {
                if(j==i)
                    continue;
                else
                    temp=temp+(matrix[i][j]*var_arr[j]);
            }
            temp=((matrix[i][col-1])-(temp))/matrix[i][i];
            var_arr[i]=temp;
            temp=0;
        }
        count++;
    }
    printf("The Approximated Values Upto A Order Of %d Are: ",limit);
    disparr(var_arr,row);
}

int main(void)
{
    int row,col;
    float matrix[20][20];
    printf("Enter the number of rows: ");
    scanf("%d",&row);
    printf("Enter the number of columns: ");
    scanf("%d",&col);
    printf("\nEnter %d elements of the matrix:\n",row*col);
    matinit(matrix,row,col);
    printf("\n%d elements of the matrix are: \n",row*col);
    matdisp(matrix,row,col);
    Gauss_Jacobi(matrix,row,col);

}
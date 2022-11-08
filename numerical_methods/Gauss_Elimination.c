#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void getmatrix(float (*mat)[20],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            scanf("%f",&mat[i][j]);
    printf("Enter the values of the right hand vector: \n");
    for(i=0;i<col;i++)
            scanf("%f",&mat[i][col]);
}

void dispmatrix(float (*mat)[20],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            printf("%.2f\t",mat[i][j]);
        printf("\n");
    }
}

void row_oper(float(*mat)[20],int rc,int r,int ord,float mult)
{
    int j;
    for(j=0;j<ord+1;j++)
    {
        mat[rc][j]=mat[rc][j]+(mat[r][j]*mult);
    }
}

void Gauss_Elimination(float(*mat)[20],int ord)
{
    int i,j;
    float mult,soln=0.0f;
    for(i=1;i<ord;i++)
        for(j=0;j<i;j++)
        {
            mult=-(mat[i][j]/mat[j][j]);
            row_oper(mat,i,j,ord,mult);
        }
    printf("Coefficient Matrix After Operations:\n");
    dispmatrix(mat,ord,ord+1);
    for(i=ord-1;i>=0;i--)
    {
        for(j=ord-1;j>=i;j--)
        {
            if(mat[i][j-1]==0.0f)
            {
                soln=(mat[i][ord]-soln)/mat[i][j];
                printf("\nsolnfinal:%f",soln);
            }
            else
            {
                soln=soln*mat[i][j];
                printf("\nsoln:%f",soln);
            }
        }
        
    }
}

int main(void)
{
    float mat[20][20];
    int ord;
    memset(mat,0.0f,sizeof(mat));
    printf("Enter the order of the coefficient matrix: ");
    scanf("%d",&ord);
    printf("Enter %d elements of the coefficient matrix: \n",ord*ord);
    getmatrix(mat,ord,ord);
    printf("Entered Matrix\n");
    dispmatrix(mat,ord,ord+1);
    Gauss_Elimination(mat,ord);
    return 0;

}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void getmatrix(double (*mat)[20],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            scanf("%lf",&mat[i][j]);
    printf("Enter the values of the right hand vector: \n");
    for(i=0;i<col;i++)
            scanf("%lf",&mat[i][col]);
}

void dispmatrix(double (*mat)[20],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            printf("%.2f\t",mat[i][j]);
        printf("\n");
    }
}

void row_oper(double(*mat)[20],int rc,int r,int ord,double mult)
{
    int j;
    for(j=0;j<ord+1;j++)
    {
        mat[rc][j]=mat[rc][j]+(mat[r][j]*mult);
    }
}

void back_sub(double(*mat)[20],int ord)
{
	int i,j;
	double x[20],sum=0;
	x[ord-1]=mat[ord-1][ord]/mat[ord-1][ord-1];
	for(i=ord-2;i>=0;i--)
	{
		sum=0;
		for(j=ord-1;j>=i;j--)
			sum=sum+(mat[i][j]*x[j]);
		x[i]=(mat[i][ord]-sum)/mat[i][i];
	}
	printf("The Solutions are: \n");
	for(i=0;i<ord;i++)
		printf("x%d=%lf\n",i,x[i]);
}

void Gauss_Elimination(double(*mat)[20],int ord)
{
    int i,j;
    double mult,soln=0.0f;
    for(i=1;i<ord;i++)
        for(j=0;j<i;j++)
        {
            mult=-(mat[i][j]/mat[j][j]);
            row_oper(mat,i,j,ord,mult);
        }
    printf("Augmented Matrix After Operations:\n");
    dispmatrix(mat,ord,ord+1);
    back_sub(mat,ord);
}

int main(void)
{
    double mat[20][20];
    int ord;
    memset(mat,0.0f,sizeof(mat));
    printf("To solve a system of linear equations using Gauss Elimination Method");
    printf("\nEnter the order of the coefficient matrix: ");
    scanf("%d",&ord);
    printf("Enter %d elements of the coefficient matrix: \n",ord*ord);
    getmatrix(mat,ord,ord);
    printf("Entered Matrix\n");
    dispmatrix(mat,ord,ord+1);
    Gauss_Elimination(mat,ord);
    return 0;

}

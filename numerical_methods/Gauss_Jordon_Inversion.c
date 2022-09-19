#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
// matrix inversion 


void getmatrix(float (*mat)[20],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            scanf("%f",&mat[i][j]);
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

void setidentity(float(*mat)[20],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
        for(j=col;j<2*col;j++)
            if((i+col)==j)
                mat[i][j]=1;
}
void dividerow(float(*mat)[20],int row,int col,float num)
{
    int j;
    for(j=0;j<col;j++)
    {
        mat[row][j]=(mat[row][j]/num);
        printf("After Dividing Row: \n");
        dispmatrix(mat,2,4);
    }
}
void inverse(float(*mat)[20],int row,int col) //for the augmented matrix specifically
{
    int i,j,k=0;
    float multiplier;
    for(i=0;i<row;i++)
    {
        if(mat[i][i]!=1)
            dividerow(mat,i,col,mat[i][i]); //divides first row
        for(j=0;j<row;j++) //do row operations on the remaining rows
        {
            for(k=0;k<col;k++)
            {
                if(j==i)
                    break;
                else
                {
                    multiplier=(mat[j][i]/mat[i][i]);
                    printf("\nChosen Multiplier: %f\n",multiplier);
                    mat[j][k]=mat[j][k]-(multiplier*mat[i][k]);
                    printf("Value:%f\n",mat[j][k]);
                }
            }
        }
    }
}

int main(void)
{
    float mat[20][20];
    memset(mat,0,sizeof(mat));
    int ord,row_aug,col_aug;
    printf("Enter the order of the coefficient matrix: ");
    scanf("%d",&ord);
    row_aug=ord;
    col_aug=2*ord;
    printf("Enter %d elements of the coefficient matrix: \n",ord*ord);
    getmatrix(mat,ord,ord);
    printf("Entered Matrix\n");
    dispmatrix(mat,ord,ord);
    setidentity(mat,ord,ord); //not on augmented but on identity
    printf("Generated Augmented Matrix:\n");
    dispmatrix(mat,row_aug,col_aug);
    inverse(mat,row_aug,col_aug);
    printf("Inverse:\n");
    dispmatrix(mat,row_aug,col_aug);
    return 0;

}
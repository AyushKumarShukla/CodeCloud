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
        //printf("After Dividing Row: \n");
        //dispmatrix(mat,2,4);
    }
}
void inverse(float(*mat)[20],int row,int col) 
{
    int i,j,k=0;
    float multiplier;
    for(i=0;i<row;i++) //loop for identifying diagonal elements 
    {
        if(mat[i][i]!=1)
            dividerow(mat,i,col,mat[i][i]); //This makes the diagonal element value 1 if it isn't already
        for(j=0;j<row;j++) // loop for traversing row
        {
	    multiplier=(mat[j][i]/mat[i][i]);//caution,this statement must not be in the loop below,the used value gets set to 0
            for(k=0;k<col;k++) //loop for traversing col
            {
                if(j==i) //if the row value is same as the row of current diagonal element
                    break;
                else
                {
                    //printf("\nChosen Multiplier: %f\n",multiplier);
                    mat[j][k]=mat[j][k]-(multiplier*mat[i][k]); //performing row operation on all values of the row
                    //printf("Value:%f\n",mat[j][k]);
                }
            }
        }
    }
}

void mult(float(*mat)[20],float *rhv,int ord)
{
	int i,j;
	float res=0;
 	for(i=0;i<ord;i++)
	{
 		for(j=ord;j<2*ord;j++)
 		{
			res=res+(mat[i][j]*rhv[j-ord]);
		}
		printf("X%d = %f\n",i,res);
 		res=0;
	}
}

int main(void)
{
    float mat[20][20],rhv[20];
    memset(mat,0,sizeof(mat));
    int ord,row_aug,col_aug,i;
    printf("To solve a given set of linear equations using Gauss-Jordon Inversion Method:\n");
    printf("Enter the order of the coefficient matrix: ");
    scanf("%d",&ord);
    row_aug=ord; // no of rows in augmented matrix
    col_aug=2*ord; // no of cols in augmented matrix
    printf("Enter %d elements of the coefficient matrix: \n",ord*ord);
    getmatrix(mat,ord,ord);
    printf("Entered Matrix\n");
    dispmatrix(mat,ord,ord);
    setidentity(mat,ord,ord); //Augmenting coefficient matrix with a identity matrix
    printf("Generated Augmented Matrix:\n");
    dispmatrix(mat,row_aug,col_aug);
    inverse(mat,row_aug,col_aug);
    printf("Inverse Augmented Matrix:\n");
    dispmatrix(mat,row_aug,col_aug);
    printf("Enter %d elements of the right hand vector: ",ord);
    for(i=0;i<ord;i++)
	scanf("%f",&rhv[i]);
    printf("Solution: \n");
    mult(mat,rhv,ord);
    return 0;

}

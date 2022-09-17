/*Pointer To an array*/

#include<stdio.h>

#include<stdio.h>
#define ROW 4
#define COLUMN 4
void getmatrix(int p[][COLUMN],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            scanf("%d",&p[i][j]);
    }
}

void dispmatrix(int(*p)[COLUMN],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            printf("Value->%d Address->%u\n",p[i][j],&p[i][j]);
        printf("\n");
    }
}

int main(void)
{
    int arr[ROW][COLUMN],row,col,i,j;
    printf("Enter the number of rows needed: ");
    scanf("%d",&row);
    printf("Enter the number of columns needed: ");
    scanf("%d",&col);
    printf("Enter %d Elements: ",row*col);
    getmatrix(arr,row,col);
    printf("Entered Matrix: \n");
    dispmatrix(arr,row,col);
}
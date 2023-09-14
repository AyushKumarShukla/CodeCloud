#include<stdio.h>
#include<stdlib.h>

//function to dynamically allocate a 2-D array using array of pointers
int** creatematrix(int row,int col)
{
    int i;
    int** arr;
    arr=(int**)malloc(row*sizeof(int*)); //creating an array of pointers of size equal to row
    for(i=0;i<row;i++)
        arr[i]=(int*)malloc(col*sizeof(int));//pointing each pointer in array of pointers to a 1-D array of size col
    return arr;
}
//function to take input in a matrix
void getmatrix(int **arr,int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            scanf("%d",&arr[i][j]);
}
//function to display a matrix
void dispmatrix(int **arr,int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            printf("%d\t",arr[i][j]);
        printf("\n");
    }
}
int main(void)
{
    int** arr;
    int row,col;
    printf("To display a matrix: \n");
    printf("Enter the number of rows needed: ");
    scanf("%d",&row);
    printf("Enter the number of columns needed: ");
    scanf("%d",&col);
    arr=creatematrix(row,col); //dynamic allocation of 2-D array 
    printf("Enter %d elements: \n",row*col);
    getmatrix(arr,row,col);
    printf("Entered elements: \n");
    dispmatrix(arr,row,col);
    return 0;

}

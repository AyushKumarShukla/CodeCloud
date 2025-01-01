#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


#define MAX_SIZE 20
typedef struct sparsemat
{
    int ROW_CNT;
    int values[20][3];
}sparsemat;

void init3Tuple(sparsemat* spmat,int row)
{
    int i,j;
    spmat->ROW_CNT = 0;

    for(i=0;i<row;i++)
        for(j=0;j<3;j++)
            spmat->values[i][j] = 0;
}

void display3Tuple(sparsemat* mat)
{
    int i,j;
    printf("\n");
    printf("ROW\tCOL\tDATA\n");
        for(i=0;i<(mat->ROW_CNT);i++)
        {
            for(j=0;j<3;j++)
            {
                printf("%d\t",mat->values[i][j]);
            }
            printf("\n");
        }
}

void transpose(sparsemat* spmat)
{
    int i,j,temp;
    for(i=0;i<spmat->ROW_CNT;i++)
    {
        temp = spmat->values[i][0];
        spmat->values[i][0] = spmat->values[i][1];
        spmat->values[i][1] = temp;
    }
}

void insert3Tuple(int row,int col,int data, sparsemat* spmat)
{
    spmat->values[spmat->ROW_CNT][0] = row;
    spmat->values[spmat->ROW_CNT][1] = col;
    spmat->values[spmat->ROW_CNT][2] = data;
    spmat->ROW_CNT++;
}

void convert3Tuple(int(*mat)[20],sparsemat* spmat, int rowcnt,int colcnt)
{
    int i,j;
    for(i=0;i<rowcnt;i++)
        for(j=0;j<colcnt;j++)
        {
            if(mat[i][j]!=0)
            {
                insert3Tuple(i,j,mat[i][j],spmat);
            }
        }
}
int compare3Tuple(const void *a, const void *b) {
    int *tuple1 = (int *)a;
    int *tuple2 = (int *)b;

    // Compare ROW first
    if (tuple1[0] < tuple2[0]) return -1;
    if (tuple1[0] > tuple2[0]) return 1;

    // If ROW is the same, compare COL
    if (tuple1[1] < tuple2[1]) return -1;
    if (tuple1[1] > tuple2[1]) return 1;

    return 0; // If all values are equal
}
int main(void)
{
    int ch;
    int mat[MAX_SIZE][MAX_SIZE];

    sparsemat spmat;
    int row,col;
    int i,j;

    while(true)
    {
        printf("\nMENU:\n");
        printf("1.Input\n2. Display original mat\n3. Display 3-tuple rep \n4. Transpose\n5.Generate 3 Tuple\n6. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter number of rows and cols: ");
                scanf("%d%d",&row,&col);
                printf("Enter %d elements of the matrix: ",row*col);
                for(i=0;i<row;i++)
                    for(j=0;j<col;j++)
                        scanf("%d",&mat[i][j]);   
                init3Tuple(&spmat,row);
                break;
            case 2:
                printf("Entered Matrix:\n");
                for(i=0;i<row;i++)
                {
                    for(j=0;j<col;j++)
                    {
                        printf("%d\t",mat[i][j]);
                    }
                    printf("\n");
                }

                break;
            
            case 3:
                qsort(spmat.values, spmat.ROW_CNT, sizeof(spmat.values[0]), compare3Tuple);
                display3Tuple(&spmat);
                break;
            case 4:
                transpose(&spmat);
                break;
            case 5:
                convert3Tuple(mat,&spmat,row,col);
                break;
            case 6:
                exit(0);
                break;
        }
    }
    printf("\n");
    return 0;
}

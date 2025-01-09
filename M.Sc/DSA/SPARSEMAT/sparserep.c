#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

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
// return the number of non zero elements in the matrix
int NNZ(int(*mat)[20],int rowcnt, int colcnt)
{
    int i,j;
    int nnzcnt = 0;
    for(i=0;i<rowcnt;i++)
     for(j=0;j<colcnt;j++)
        if(mat[i][j] != 0)
            nnzcnt++;
    return nnzcnt;
}

bool verify(int nnzcnt,int row,int col)
{
    int size = row * col;
    if(size % 3 == 0)
        return(nnzcnt < (size/3));
    else
        return(nnzcnt < ceil(((double)size/3.0)));
}
int main(void)
{
    int ch;
    int mat[MAX_SIZE][MAX_SIZE];
    bool matinit = false;
    bool sparseinit = false;
    sparsemat spmat;
    int row,col;
    int i,j;

    while(true)
    {
        printf("\nMENU:\n");
        printf("1.\tInput\n2.\tDisplay original mat\n3.\tGenerate 3 Tuple Rep \n4.\tTranspose\n5.\tDisplay 3 Tuple Rep\n6.\tExit");
        printf("\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter number of rows and cols: ");
                scanf("%d%d",&row,&col);
                printf("Enter %d elements of the matrix: \n",row*col);
                for(i=0;i<row;i++)
                    for(j=0;j<col;j++)
                        scanf("%d",&mat[i][j]);   
                init3Tuple(&spmat,row);
                matinit = true;
                break;
            case 2:
                if(!matinit)
                {
                    printf("INFO:\tNO MATRIX REGISTERED\n");
                    break;
                }
                if(!sparseinit)
                {
                    printf("INFO:\t3-TUPLE REP. NOT GENERATED\n");
                    break;
                }
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
            
            case 5:
                if(!matinit)
                {
                    printf("INFO:\tNO MATRIX REGISTERED\n");
                    break;
                }
                if(!sparseinit)
                {
                    printf("INFO:\n3-TUP REP. NOT GENERATED");
                    break;
                }
                qsort(spmat.values, spmat.ROW_CNT, sizeof(spmat.values[0]), compare3Tuple);
                display3Tuple(&spmat);
                break;
            case 4:
                if(!matinit)
                {
                    printf("INFO:\tNO MATRIX REGISTERED\n");
                    break;
                }
                if(!sparseinit)
                {
                    printf("INFO:\t 3-TUPLE REP. NOT GENERATED\n");
                    break;
                }
                transpose(&spmat);
                printf("INFO:\tTRANSPOSED: 3-TUPLE REPRESENTATION\n");
                break;
            case 3:
                if(!matinit)
                {
                    printf("INFO:\tNO MATRIX REGISTERED\n");
                    break;
                }
                if(!verify(NNZ(mat,row,col),row,col))
                {
                    printf("INFO:\t Registered Matrix Not Sparse Enough.");
                    break;
                }
                convert3Tuple(mat,&spmat,row,col);
                sparseinit = true;
                printf("INFO:\tGENERATED: 3-TUPLE SPARSE MATRIX REPRESENTATION\n");
                break;
            case 6:
                exit(0);
                break;
        }
    }
    printf("\n");
    return 0;
}

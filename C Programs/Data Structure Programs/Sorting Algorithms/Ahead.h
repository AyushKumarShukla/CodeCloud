
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


void swap(int *a ,int *b)
{
    *a =*a+*b;
    *b =*a-*b;
    *a =*a-*b;
}

void getarr(int*arr,int num)
{
    int i;
    for(i=0;i<num;i++)
            scanf("%d",&arr[i]);
}

void disparr(int*arr,int num)
{
    int i;
    for(i=0;i<num;i++)
        printf("%d ",arr[i]);
}

void bubblesort(int* arr,int len)
{
    int i,j;

    for(i=0;i<len-1;i++)
    {
        for(j=0;j<len-1-i;j++)
        {
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
        }
    }
}



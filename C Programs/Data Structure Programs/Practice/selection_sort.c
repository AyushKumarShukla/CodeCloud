#include<stdio.h>
#include<stdlib.h>

void getarr(int *arr,int num)
{
    int i;
    for(i=0;i<num;i++)
        scanf("%d",&arr[i]);
}

void disparr(int *arr, int num)
{
    int i;
    for(i=0;i<num;i++)
        printf("%d ",arr[i]);
}

int findmin(int *arr,int start,int num)
{
    int i,minloc;
    minloc=start;
    for(i=start+1;i<num;i++)
        if(arr[i]<arr[minloc])
            minloc=i;
    return minloc;
}

void swap(int *a,int *b)
{
    *a=*a+*b;*b=*a-*b;*a=*a-*b;
}

void selection_sort(int *arr,int num)
{
    int i,j,minloc;
    for(i=0;i<num-1;i++)
    {
        minloc = findmin(arr,i,num);
        if(minloc!=i)
            swap(&arr[minloc],&arr[i]);
        printf("\nPASS %d: ",i+1);
            disparr(arr,num);
    }
}

int main(void)
{
    int num,*arr;
    printf("Enter the number of elements: ");
    scanf("%d",&num);
    arr=(int*)malloc(num*sizeof(int));
    printf("Enter %d elements: ",num);
    getarr(arr,num);
    printf("Entered list: ");
    disparr(arr,num);
    selection_sort(arr,num);
    printf("\nSorted List: ");
    disparr(arr,num);
    return 0;
}
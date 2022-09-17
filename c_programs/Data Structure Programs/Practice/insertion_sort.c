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

void insertion_sort(int *arr,int num) //inplace
{
    int i,j,val;
    for(i=0;i<num;i++)
    {
        val=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>val)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=val;
        printf("\nPASS:%d ",i+1);
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
    insertion_sort(arr,num);
    printf("\nSorted List: ");
    disparr(arr,num);
    return 0;
}
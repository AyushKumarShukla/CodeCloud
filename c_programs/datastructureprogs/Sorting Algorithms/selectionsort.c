#include<stdio.h>

void swap(int*a,int*b)
{
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}

void getarr(int* arr,int num)
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

int findmin(int*arr,int start, int num)
{
    int i,minloc;
    for(i=start;i<num;i++)
        if(arr[i]<arr[minloc])
            minloc=i;
    return minloc;
}

void selectionsort(int *arr,int num)
{
    int i,j,minloc;
    for(i=0;i<num-1;i++)
    {
        minloc=i;
        for(j=minloc+1;j<num;j++)
            minloc=findmin(arr,j,num);
        if(i!=minloc)
            swap(&arr[i],&arr[minloc]);
    }
}   

int main(void)
{
    int arr[50],num;
    printf("Enter The Length Of The List: ");
    scanf("%d",&num);
    printf("Enter %d elements:",num);
    getarr(arr,num);
    printf("Entered Elements :");
    disparr(arr,num);
    selectionsort(arr,num);
    printf("Sorted Array: ");
    disparr(arr,num);
}
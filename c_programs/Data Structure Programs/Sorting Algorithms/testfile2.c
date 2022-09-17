#include<stdio.h>
#include"Ahead.h"

int main(void)
{
    int arr[50],num;
    printf("Enter the length of the array: ");
    scanf("%d",&num);
    printf("Enter %d elements of array: ");
    getarr(arr,num);
    bubblesort(arr,num);
    disparr(arr,num);
}
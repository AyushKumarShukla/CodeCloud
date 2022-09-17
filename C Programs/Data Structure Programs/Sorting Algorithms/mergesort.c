#include<stdlib.h>
#include<stdio.h>

void getarr(int *arr,int size)
{
    int i;
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
}

void disparr(int *arr,int size)
{
    int i;
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
}
//function to merge two subarrays of a single array
void merge(int *arr,int left,int mid,int right)
{
    int sorted[20],i,j,k=left;
    i=left; //starting index of the left subarray
    j=mid+1; //starting index of the right subarray
    while(i<=mid && j<=right) //while both arrays are not exhausted
    {
        if(arr[i]<=arr[j]) //if left subarray element is greater
        {
            sorted[k]=arr[i]; //put the element in sorted array
            k++;i++;
        }
        else
        {
            sorted[k]=arr[j]; //otherwise put the right subarray element
            k++;j++;
        }
    }
    while(i<=mid) //if left subarray is remaining
    {
        sorted[k]=arr[i]; //copy all remaining elements
        k++;i++;
    }

    while(j<=right) //if right subarray is remaining
    {
        sorted[k]=arr[j]; //copy all remaining elements
        k++;j++;
    }
    
    for(i=left;i<=right;i++) //copy the sorted array into the original array
        arr[i]=sorted[i];
}
//recursive function to divide the array into subarrays
void mergesort(int *arr,int left,int right)
{
    int mid;
    if(right<=left) //recursion termination condition
        return;
    else
    {
        mid=(left+right)/2; //calculation of middle index
        mergesort(arr,left,mid); // divide for the left subarray
        mergesort(arr,mid+1,right); // divide for the right subarray
        merge(arr,left,mid,right); // conquer the divided arrays by merging
    }
}

int main(void)
{
    int *arr,size,left=0,right;
    printf("To sort a list of integers using Merge Sort: \n");
    printf("Enter the number of elements needed: ");
    scanf("%d",&size);
    if(size<1) //input validation
    {
    	printf("Invalid array size, please try again");
    	exit(1);
	}
    right=(size-1);
    arr=(int*)malloc(size*sizeof(int));
    printf("Enter %d elements of the array: ",size);
    getarr(arr,size);
    printf("Entered array: ");
    disparr(arr,size);
    mergesort(arr,left,right);
    printf("\nSorted Array: ");
    disparr(arr,size);
    return 0;
}

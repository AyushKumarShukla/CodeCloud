/*WAP in C to implement Quick Sort*/

#include<stdio.h>
#include<stdlib.h>
//function to take input in an array
void getarr(int *arr,int size)
{
    int i;
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
}
//function to display an array
void disparr(int *arr,int size)
{
    int i;
    for(i=0;i<size;i++) 
        printf("%d ",arr[i]);
}
//function to swap two variables
void swap(int *a,int*b)
{
    *a=*a+*b; 
    *b=*a-*b;
    *a=*a-*b;
}
//function to divide the array using pivot element
int partition(int *arr,int left,int right)
{
    int loc=left; //selecting left as pivot element
    while(left<right) //traversing the whole array
    {
        while(arr[right]>=arr[loc] && loc<right)//while right element is greater/equal to pivot element
            right--;//decrement right
        if(arr[right]<arr[loc])//if right element is less than pivot element
        {
            swap(&arr[loc],&arr[right]);//swap right and pivot elements
            loc=right;//set pivot location to right
            left++;//left to right scan starts from left+1
        }
        while(arr[left]<=arr[loc] && left<loc )//while left element is smaller/equal to pivot element
            left++;//increment left
        if(arr[left]>arr[loc])//if left element is greater than pivot element
        {
            swap(&arr[left],&arr[loc]);//swap left and pivot element
            loc=left;//set pivot location to left
            right--;//right to left scan starts from right-1
        }
    }
    return loc;
}

void quicksort(int *arr,int left,int right)
{
    int loc;
    if(left<right)//while there are more than one element
    {
        loc=partition(arr,left,right);//find pivot location
        quicksort(arr,left,loc-1);//sort left subarray
        quicksort(arr,loc+1,right);//sort right subarray
    }
}
//function for input validation
void validate(int size)
{
    if(size<2)
    {
        printf("The size must be atleast two");
        exit(1);
    }
}

int main(void)
{
    int *arr,size,left=0,right;
    printf("To sort a list of integers using Quick Sort:\n");
    printf("Enter the number of elements needed: ");
    scanf("%d",&size);
    validate(size);//validating input
    right=size-1;
    arr=(int*)malloc(size*sizeof(int));
    printf("Enter %d elements of the array: ",size);
    getarr(arr,size);
    printf("Entered array: ");
    disparr(arr,size);
    quicksort(arr,left,right);
    printf("\nSorted array: ");
    disparr(arr,size);
    return 0;
}
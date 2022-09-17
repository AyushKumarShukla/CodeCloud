/*C program to implement selection sort*/

#include<stdio.h>
#include<stdlib.h>


int main(void)
{
    int arr[50];
    int num,i,j,minloc,temp;
    printf("Enter the number of elements needed: ");
    scanf("%d",&num);
    printf("\nEnter array elements: ");
    for(i=0;i<num;i++)
        scanf("%d",&arr[i]);
    printf("Entered array: ");
    for(i=0;i<num;i++)
        printf("%d ",arr[i]);

    for(j=0;j<num-1;j++)
    {
        minloc=j;
        for(i=j+1;i<num;i++)
            if(arr[i]<arr[minloc])
                minloc=i;
            
        arr[j]=arr[j]+arr[minloc];
        arr[minloc]=arr[j]-arr[minloc];
        arr[j]=arr[j]-arr[minloc];
        
    }

    printf("\nSorted Array: ");
    for(i=0;i<num;i++)
        printf("%d ",arr[i]);
    return 0;
    
}
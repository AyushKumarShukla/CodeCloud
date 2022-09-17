#include<stdio.h>

int main(void)
{
    int arr[50],num,i,temp;
    printf("Enter the size of the array: ");
    scanf("%d",&num);
    printf("\nEnter %d elements: ",num);
    for(i=0;i<num;i++)
        scanf("%d",&arr[i]);

    printf("\nELEMENTS: ",num);
    for(i=0;i<num;i++)
        printf("%d",arr[i]);
    
    for(i=0;i<num;i++)
        if(arr[i]>arr[i+1])
        {   
            temp=arr[i+1];
            arr[i+1]=arr[i];
            arr[i]=temp;
        }
    printf("\nSORTED ELEMENTS: ",num);
    for(i=0;i<num;i++)
        printf("%d",arr[i]);   
}
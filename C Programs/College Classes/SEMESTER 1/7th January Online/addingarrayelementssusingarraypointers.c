#include<stdio.h>

int main(void)
{
    int arr[5],i,*ptr,sum=0;
    printf("Enter five elements of array: ");
    ptr = arr;
    for(i=0;i<5;i++)
        scanf("%d",ptr++);
    printf("\n");
    ptr=arr;//to bring the pointer back home
    for(i=0;i<5;i++)
        printf("%d",*(ptr++));
    ptr=arr;
    for(i=0;i<5;i++)
        sum = sum + *(ptr++);
    printf("\nSum of the elements:%d",sum);
    return 0;

}
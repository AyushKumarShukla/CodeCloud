//Using Functions With Arrays

#include<stdio.h>

void inp(int *arr,int num)
{
    int i;
    printf("Enter the elements of the array: ");
    for(i=0;i<num;i++) 
        scanf("%d",arr+i);
}
void disp(int *arr,int num)
{
    int i;
    printf("\nThe Elements Of The Array Are: ");
    for(i=0;i<num;i++)
        printf("%d ",*(arr+i));
}


int main(void)
{
    int arr[50],num;
    while(1)
    {  printf("Enter the number of elements");
        scanf("%d",&num);
        if(num>50)
            printf("Invalid Input-Try Again\n");
        else
            break;
    }
    inp(arr,num);
    disp(arr,num);
}
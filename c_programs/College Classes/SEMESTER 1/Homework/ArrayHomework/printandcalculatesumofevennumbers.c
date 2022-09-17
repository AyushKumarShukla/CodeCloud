//WAP to print and calculate the sum of all even numbers in an array

#include<stdio.h>

void input(int* ptr,int num)
{
    int i;
    printf("Enter the elements of the array: ");
    for(i=0;i<num;i++)
        scanf("%d",&ptr[i]);
}

void dispevennum(int *ptr,int num)
{
    int i,sum=0;
    printf("The even numbers in the array are: ");
    for(i=0;i<num;i++)
    {
        if(ptr[i]%2==0)
          { 
            printf("%d ",ptr[i]);
            sum = sum + ptr[i];
          }
    }
    printf("\nThe sum of all even numbers is: %d",sum);
}

int main(void)
{
    int arr[50],num,sum,i,*ptr;
    ptr=arr;
    while(1)
    {
        printf("Enter the number of elements: ");
        scanf("%d",&num);
        if(num>50)
            printf("Wrong input-Please try again");
        else
            break;
    }
    input(ptr,num);
    dispevennum(ptr,num);
    return 0;
}
/*
OUTPUT:
Enter the number of elements: 5
Enter the elements of the array: 1 2 3 4 1
The even numbers in the array are: 2 4
The sum of all even numbers is: 6
--------------------------------
Process exited after 14.99 seconds with return value 0
Press any key to continue . . .*/

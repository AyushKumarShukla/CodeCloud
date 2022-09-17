/*WAP in C to print an array in reverse order*/

#include<stdio.h>

void input(int *ptr,int num)
{
    int i;
    printf("Enter the elements of the array: ");
    for(i=0;i<num;i++)
        scanf("%d",&ptr[i]);
}

void disprev(int* ptr,int num)
{
    int i;
    printf("The elements in reverse order are: ");
    for(i=num-1;i>=0;i--)
        printf("%d ",ptr[i]);
}


int main(void)
{
    int arr[50],num,*ptr,i;
    ptr=arr;
    while(1)
    {
        printf("Enter the number of elements needed: ");
        scanf("%d",&num);
        if(num>50)
            printf("Wrong input - try again");
        else
            break;
    }
    input(ptr,num);
    disprev(ptr,num);
    return 0;
}

/*
OUTPUT:
Enter the number of elements needed: 5
Enter the elements of the array: 1 2 3 4 5
The elements in reverse order are: 5 4 3 2 1
--------------------------------
Process exited after 7.889 seconds with return value 0
Press any key to continue . . .*/

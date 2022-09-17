/*WAP in C to print the even positioned elements of an array*/
#include<stdio.h>

void input(int* ptr,int num)
{
    int i;
    printf("Enter the values of array: ");
    for(i=0;i<num;i++)
        scanf("%d",&ptr[i]);
}

void disp(int *y,int j)
{
    int i;
    printf("The elements you entered are: ");
    for(i=0;i<j;i++)
        printf("%d ",y[i]);
}

void dispevenpos(int *ptr,int num)
{
    int i;
    printf("\nThe even positioned elements are: ");
    for(i=1;i<num;i=i+2)
        printf("%d ",ptr[i]);
}


int main(void)
{
    int arr[50],*ptr,i,num;
    ptr=arr;
    while(1)
    {
        printf("Enter the number of elements<50: ");
        scanf("%d",&num);
        if(num>50)
            printf("Wrong input-Try Again");
        else
            break;
    }
    input(ptr,num);
    disp(ptr,num);
    dispevenpos(ptr,num);

    return 0;
}

/*
OUTPUT:
Enter the number of elements<50: 5
Enter the values of array: 1 2 3 4 5
The elements you entered are: 1 2 3 4 5
The even positioned elements are: 2 4
--------------------------------
Process exited after 9.242 seconds with return value 0
Press any key to continue . . .
*/
   

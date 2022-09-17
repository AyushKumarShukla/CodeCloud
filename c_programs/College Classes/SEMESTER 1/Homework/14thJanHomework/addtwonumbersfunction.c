/*WAP in C to add two numbers using functions*/

#include<stdio.h>

int add(int x, int y)
{
    return x+y;
}

int main(void)
{
    int num1,num2,sum=0;
    printf("Enter two numbers: ");
    scanf("%d%d",&num1,&num2);
    printf("The sum of %d and %d is %d",num1,num2,add(num1,num2));
    return 0;
}

/*
OUTPUT
Enter two numbers: 1 6
The sum of 1 and 6 is 7
--------------------------------
Process exited after 2.472 seconds with return value 0
Press any key to continue . . .
*/

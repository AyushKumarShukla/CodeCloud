/*Write a program in C to compute the sum of the first n terms of the following series:

S = 1+1/2+1/3+1/4+……...
*/

#include<stdio.h>

int main(void)
{
    int num,i;
    float sum=0;
    printf("Enter the number of elements needed: ");
    scanf("%d",&num);

    for(i=1;i<=num;i++)
    {
        sum = sum + 1.0/i;
    }
    printf("The sum of the series is : %f",sum);
    return 0;
}
/*
OUTPUT
SET 1:
Enter the number of elements needed: 2
The sum of the series is : 1.500000
--------------------------------
Process exited after 1.294 seconds with return value 0
Press any key to continue . . .

SET 2:
Enter the number of elements needed: 5
The sum of the series is : 2.283334
--------------------------------
Process exited after 1.187 seconds with return value 0
Press any key to continue . . .

SET 3:
Enter the number of elements needed: 1000
The sum of the series is : 7.485478
--------------------------------
Process exited after 1.716 seconds with return value 0
Press any key to continue . . .
*/

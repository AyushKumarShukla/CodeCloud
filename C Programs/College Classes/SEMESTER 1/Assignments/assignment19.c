/*Write a program in C to compute the sum of the first n terms of the following series:

S = 1-2+3-4+5.......
*/

#include<stdio.h>

int main(void)
{
    int num,i,sign,sum=0;
    printf("Enter the number of terms needed: ");
    scanf("%d",&num);

    for(i=1;i<=num;i++)
    {
        if(i%2==0)
            sign = -1;
        else
            sign = 1;
        
        sum = sum + (i*sign);
//        printf("TEST sum:%d\n",sum);
    }
    printf("The sum of the series is : %d",sum);
    return 0;
}
// if the number of terms is even , the sum of series is -n/2
// if the number of terms is odd, the sum of series is +n/2

/*
OUTPUT
SET 1:
Enter the number of terms needed: 2
The sum of the series is : -1
--------------------------------
Process exited after 1.34 seconds with return value 0
Press any key to continue . . .

SET 2:
Enter the number of terms needed: 5
The sum of the series is : 3
--------------------------------
Process exited after 1.202 seconds with return value 0
Press any key to continue . . .

SET 3:
Enter the number of terms needed: 587
The sum of the series is : 294
--------------------------------
Process exited after 1.231 seconds with return value 0
Press any key to continue . . .

*/

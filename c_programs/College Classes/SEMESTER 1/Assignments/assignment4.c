/*Write a program in C to find out the sum and product of the digits of an integer*/

#include<stdio.h>

int digitsum(int num)
{
	int i=1,digit,n,sum=0;
	n = num;
	while(num>0)
	{
		i++;
		digit = num%10;
		num = num/10;
		sum = sum + digit;
	}
	return sum;
}

int digitprod(int num)
{
	int i=1,digit,prod=1;

	while(num>0)
	{
		i++;
		digit = num%10;//23
		num = num/10;
		prod=prod*digit;
	}
	return prod;
}



int main(void)
{
	int num,product,sum;
	printf("Enter a number: ");
	scanf("%d",&num);
	sum = digitsum(num);
	product = digitprod(num);
	printf("SUM:%d",sum);
	printf("\nPRODUCT:%d",product);
	return 0 ;
	
}

/*OUTPUT
SET 1:
Enter a number: 12
SUM:3
PRODUCT:2
--------------------------------
Process exited after 4.677 seconds with return value 0
Press any key to continue . . .

SET 2:
Enter a number: 125
SUM:8
PRODUCT:10
--------------------------------
Process exited after 3.319 seconds with return value 0
Press any key to continue . . .

SET 3:
Enter a number: 1239
SUM:15
PRODUCT:54
--------------------------------
Process exited after 1.831 seconds with return value 0
Press any key to continue . . .
*/


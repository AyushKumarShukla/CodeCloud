/*Write a program in C to find out the reverse of a number*/

#include<stdio.h>

void reverse(usr_num)
{
	int n,digit;
	n = usr_num;
	while(n>0)
	{
		digit = n%10;
		n = n/10;
		printf("%d",digit);
	}
}




int main(void)
{
	int usr_num;
	printf("Enter a number: ");
	scanf("%d",&usr_num);
	reverse(usr_num);
	return 0;
	
}
/*
OUTPUT
SET 1:
Enter a number: 12
21
--------------------------------
Process exited after 1.261 seconds with return value 0
Press any key to continue . . .

SET 2:
Enter a number: 125
521
--------------------------------
Process exited after 3.398 seconds with return value 0
Press any key to continue . . .

SET 3:
Enter a number: 123456789
987654321
--------------------------------
Process exited after 3.024 seconds with return value 0
Press any key to continue . . .




*/

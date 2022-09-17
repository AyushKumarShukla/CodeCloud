/*Write a program in C to check whether a number is a palindrome or not*/

#include<stdio.h>

void is_palin(usr_num)
{
	int num,reverse=0,remainder;
	num = usr_num;
	
	while(num>0)
	{
		remainder = num%10;
		reverse = reverse*10 + remainder; // this logic changes the position of digits in reverse order. Eg. if 12 is entered ,2 is shifted to 10's place where it becomes 20 and then 1 is added to it giving 21.
		num = num/10;
	}
	if(reverse==usr_num)
		printf("PALINDROME");
	else
		printf("NOT PALINDROME");
	return;
}


int main(void)
{
	int usr_num;
	printf("Enter a number: ");
	scanf("%d",&usr_num);
	is_palin(usr_num);
	return 0;
}

/*
OUTPUT:
SET 1:
Enter a number: 1551
PALINDROME
--------------------------------
Process exited after 2.896 seconds with return value 0
Press any key to continue . . .

SET 2:
Enter a number: 15489
NOT PALINDROME
--------------------------------
Process exited after 2.232 seconds with return value 0
Press any key to continue . . .

SET 3:
Enter a number: 99
PALINDROME
--------------------------------
Process exited after 8.521 seconds with return value 0
Press any key to continue . . .
*/

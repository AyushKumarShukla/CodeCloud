/*Write a program in C to check a given number is prime or not*/

#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool is_prime(int num)
{
	int i,flag=0;
	for(i=2;i<=sqrt(num);i++)
	{
		if(num%i==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
		return true;
	else
		return false;
}


int main(void)
{
	int num;
	printf("Enter a number: ");
	scanf("%d",&num);
	if(is_prime(num))
		printf("%d IS PRIME",num);
	else
		printf("%d IS NOT PRIME",num);
	return 0;
}

/*OUTPUT
SET 1:
Enter a number: 27
27 IS NOT PRIME
--------------------------------
Process exited after 2.954 seconds with return value 0
Press any key to continue . . .

SET 2:
Enter a number: 87
87 IS NOT PRIME
--------------------------------
Process exited after 1.561 seconds with return value 0
Press any key to continue . . .

SET 3:
Enter a number: 997
997 IS PRIME
--------------------------------
Process exited after 1.616 seconds with return value 0
Press any key to continue . . .

*/


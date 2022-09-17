/*WAP in C to find the prime factors of a given number*/

#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool isprime(int num)
{
	int j,flag=0;
	for(j=2;j<=sqrt(num);j++)
	{
		if(num%j==0)
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
	int num,i;
	printf("Enter a number: ");
	scanf("%d",&num);
	
	printf("THE PRIME FACTORS OF %d ARE: ",num);
	//Counting The Factors
	for(i=2;i<=num;i++)
	{
		if(num%i==0)
		{
			if(isprime(i)) // Checking if num is prime
			 printf("%d ",i);
		}
	}
	return 0;
	
}

/*
OUTPUT:
SET 1:
Enter a number: 125
THE PRIME FACTORS OF 125 ARE: 5
--------------------------------
Process exited after 6.387 seconds with return value 0
Press any key to continue . . .

SET 2:
Enter a number: 254
THE PRIME FACTORS OF 254 ARE: 2 127
--------------------------------
Process exited after 2.75 seconds with return value 0
Press any key to continue . . .

SET 3:
Enter a number: 548789
THE PRIME FACTORS OF 548789 ARE: 293 1873
--------------------------------
Process exited after 2.198 seconds with return value 0
Press any key to continue . . .

*/

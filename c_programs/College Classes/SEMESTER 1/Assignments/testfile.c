
#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool factors(num)
{
	int i,flag=0;
	for(i=2;i<=num;i++)
	{
		if(num%i==0)
		{
			flag=1;
		}
			
	}
	if(flag==0)
		return false;
	else
		return true;
}

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
	
	factors(num);
	
	return 0;
	
}

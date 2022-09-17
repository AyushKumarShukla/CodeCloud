/*WAP in C to print all the armstrong numbers within a given range*/

#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool isarmstrong(int num)
{
	int sum=0,n,count=0,digit;
	n=num;
	//Counting the digits
	while(n>0)
	{
		count++;
		n = n/10;	
	}
	n = num;
	
	//calculating values	
	while(n>0)
	{
		digit = n%10;
		sum = sum + pow(digit,count);
		n = n/10;
	}
	if(sum==num)
		return true;
	else
		return false;
	
}



int main(void)
{
	int lowl,uppl,i;
	printf("Enter the lower limit: ");
	scanf("%d",&lowl);
	printf("Enter the upper limit: ");
	scanf("%d",&uppl);
	
	for(i=lowl;i<=uppl;i++)
	{
		if(isarmstrong(i))
			printf("%d ",i);
	}
	return 0;		
}

/*OUTPUT
SET 1:
Enter the lower limit: 1
Enter the upper limit: 100
1 2 3 4 5 6 7 8 9
--------------------------------
Process exited after 2.162 seconds with return value 0
Press any key to continue . . .

SET 2:
Enter the lower limit: 100
Enter the upper limit: 1000
153 370 371 407
--------------------------------
Process exited after 2.382 seconds with return value 0
Press any key to continue . . .

SET 3:
Enter the lower limit: 1000
Enter the upper limit: 1000000
1634 8208 9474 54748 92727 93084 548834
--------------------------------
Process exited after 3.435 seconds with return value 0
Press any key to continue . . .
*/

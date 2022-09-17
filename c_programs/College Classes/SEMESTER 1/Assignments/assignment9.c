/*WAP in C to check whether a given number is a perfect number or not*/

#include<stdio.h>
#include<stdbool.h>

bool isperfect(num)
{
	int i,sum=0;
	for(i=1;i<num;i++)
	{
		if(num%i==0)
			sum = sum+i;
	}
	if(sum==num)
		return true;
	else
		return false;
}



int main(void)
{
	int num;
	printf("To check whether a number is perfect or not \n");
	printf("Enter a number: ");
	scanf("%d",&num);
	
	if(isperfect(num))
		printf("%d IS PERFECT",num);
	else
		printf("%d IS NOT PERFECT",num);
	
	return 0;
}
// A perfect number is such number which is equal to the sum of it's positive factors excluding the number itself

/*OUTPUT

SET 1:
To check whether a number is perfect or not
Enter a number: 6
6 IS PERFECT
--------------------------------
Process exited after 5.981 seconds with return value 0
Press any key to continue . . .

SET 2:
To check whether a number is perfect or not
Enter a number: 154
154 IS NOT PERFECT
--------------------------------
Process exited after 1.694 seconds with return value 0
Press any key to continue . . .

SET 3:
To check whether a number is perfect or not
Enter a number: 496
496 IS PERFECT
--------------------------------
Process exited after 2.277 seconds with return value 0
Press any key to continue . . .

*/

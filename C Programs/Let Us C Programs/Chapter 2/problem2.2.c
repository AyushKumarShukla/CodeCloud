/*Program to reverse a number*/
/*Author: Ayush Kumar Shukla*//*Date: 25th Nov 2021*/

#include<stdio.h>
#include<math.h>

int main()
{
	int num,d5,d4,d3,d2,d1;
	long int rev_num;
	printf("Enter a five digit number: ");
	scanf("%d",&num);
	
	d5 = num%10;
	num = num / 10;
	d4 = num%10;
	num = num/10;
	d3 = num%10;
	num = num/10;
	d2 = num%10;
	num = num/10;
	d1 = num%10;
	
	rev_num = d1*10000 + d2*1000 + d3*100 + d2*10 + d1*1;
	printf("The reverse of the number is %ld",rev_num);
	return 0 ;
	
	
	 
}

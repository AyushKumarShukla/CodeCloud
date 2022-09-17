/*Program to calculate the sum of digits of a given number*/
/*Author: Ayush Kumar Shukla*//*Date: 30th November*/

#include<stdio.h>

int main()
{
	int usr_num,num,d5,d4,d3,d2,d1,sum;
	printf("Enter a five digit number");
	scanf("%d",&usr_num);
	num = usr_num;
	
	d5 = num%10;
	num = num/10;
	d4= num%10;
	num = num/10;
	d3 = num%10;
	num = num/10;
	d2= num%10;
	num=num/10;
	d1 = num%10;
	
	sum = d1+d2+d3+d4+d5;
	printf("%d",sum);
	return 0;	
	
	
	
	
	
	
	
}

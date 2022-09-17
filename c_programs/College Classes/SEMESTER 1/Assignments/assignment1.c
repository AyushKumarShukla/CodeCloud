/*Write a program in C to implement the grading system of a student*/

#include<stdio.h>

void grade(int,int,int,int);

int main(void)
{
	int sub1,sub2,sub3,sub4;
	printf("Enter your sub1, sub2, sub3 and sub 4 marks respectively: ");
	scanf("%d%d%d%d",&sub1,&sub2,&sub3,&sub4);
	grade(sub1,sub2,sub3,sub4);
	return 0;
}

void grade(int num1, int num2 , int num3 , int num4)
{
	float prcnt;
	prcnt = ((num1+num2+num3+num4)/400.0)*100; // float division 
	
	printf("PERCENTAGE: %f\n",prcnt);
	if (prcnt>=80)
		printf("GRADE:A  PASS");
	if (prcnt>=60 && prcnt<80) 
		printf("GRADE:B	 PASS");
	if (prcnt>=40 && prcnt<60)
		printf("GRADE:C	 PASS");
	if (prcnt<40)
		printf("GRADE:D  FAIL");
	return;
}

/*
OUTPUT:
SET 1:
Enter your sub1, sub2, sub3 and sub 4 marks respectively: 80 82 84 86
PERCENTAGE: 83.000000
GRADE:A  PASS
--------------------------------
Process exited after 4.373 seconds with return value 0
Press any key to continue . . .

SET 2:
Enter your sub1, sub2, sub3 and sub 4 marks respectively: 60 62 68 72
PERCENTAGE: 65.500000
GRADE:B  PASS
--------------------------------
Process exited after 6.568 seconds with return value 0
Press any key to continue . . .

SET 3:
Enter your sub1, sub2, sub3 and sub 4 marks respectively: 40 45 60 42
PERCENTAGE: 46.750000
GRADE:C  PASS
--------------------------------
Process exited after 6.928 seconds with return value 0
Press any key to continue . . .

SET 4:
Enter your sub1, sub2, sub3 and sub 4 marks respectively: 25 26 55 41
PERCENTAGE: 36.750000
GRADE:D  FAIL
--------------------------------
Process exited after 7.385 seconds with return value 0
Press any key to continue . . .
*/







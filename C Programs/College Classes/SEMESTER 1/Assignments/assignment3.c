/*Write a program in C to find the roots of a quadratic equation*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void quadroot(float,float,float);

int main(void)
{
	float a,b,c;
	printf("Enter the values of a, b and c respectively:	");
	scanf("%f%f%f",&a,&b,&c);
	quadroot(a,b,c);
	return 0;
	
	
}

void quadroot(float a,float b,float c)
{
	float disc,root1,root2;
	
	disc = (b*b)-(4*a*c);
	
	if(a==0)
	{
		printf("INVALID DATA\nThe value of a cannot be zero");
		exit(1);
	}
	
	if(disc<0)
	{
		printf("INVALID DATA\nThe roots of this equation are imaginary");
		exit(1);
	}
	
	if(disc==0)
		printf("The roots of this equation are equal");
	
	root1 = (-b + sqrt(disc))/2*a;
	root2 = (-b - sqrt(disc))/2*a;
	
	printf("The roots of this equation are %f and %f ",root1,root2);
	return;	
}

/*
OUTPUT:
SET 1:
Enter the values of a, b and c respectively:    1 -7 -3
The roots of this equation are 7.405125 and -0.405125
--------------------------------
Process exited after 16.22 seconds with return value 0
Press any key to continue . . .

SET 2:
Enter the values of a, b and c respectively:    1 8 -84
The roots of this equation are 6.000000 and -14.000000
--------------------------------
Process exited after 34.01 seconds with return value 0
Press any key to continue . . .

SET 3:
Enter the values of a, b and c respectively:    1 -5 -24
The roots of this equation are 8.000000 and -3.000000
--------------------------------
Process exited after 7.821 seconds with return value 0
Press any key to continue . . .

SET 4:
Enter the values of a, b and c respectively:    0 1 8
INVALID DATA
The value of a cannot be zero
--------------------------------
Process exited after 4.191 seconds with return value 1
Press any key to continue . . .

SET 5:
Enter the values of a, b and c respectively:    8 1 9
INVALID DATA
The roots of this equation are imaginary
--------------------------------
Process exited after 10.03 seconds with return value 1
Press any key to continue . . .



*/



/* Program to convert one unit of length to other units of length */
/*Author: Ayush Kumar Shukla*//*Date:21 Nov 2021*/

#include<stdio.h>

int main()
{
	float distkm , distm , distft , distcm,distin;
	printf("Enter The Distance in Km");
	scanf("%f",&distkm);
	
	distm = distkm * 1000;
	distft = distkm * 3280.84;
	distin = distft * 12;
	distcm = distkm * 1e5; // mantissa e exponent - mantissa gets multiplied by 10 raised to the power exponent
	

	printf("The distance in metres = %f\n",distm);
	printf("The distance in feet = %f\n",distft );
	printf("The distance in inches = %f\n",distin);
	printf("The distance in centimeter = %f\n",distcm);
	
	return 0;

// If there are whitespaces after the newline character "\n",those whitespaces too will be forwarded to the nextline

	
}

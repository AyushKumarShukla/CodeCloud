/*Proper Division Of Two Integers*/

#include<stdio.h>

int main()
{
	float num1, num2;
	int div; // all variables are floats
	printf("Enter the values of Num1 and Num2:");
	scanf("%f%f",&num1,&num2);
	div = num1/num2; // since num1 and num2 are floats , the divis
	printf("Div=%f",div);
	
	return 0 ;
}

// In order to have fractional values upon division ,either one of the numerator or denominator must be a float 
// To store the fraction values properly , a float variable must be used

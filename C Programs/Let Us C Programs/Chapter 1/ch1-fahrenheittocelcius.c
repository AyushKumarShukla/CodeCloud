/* Program to convert the unit of temperature from fahrenheit to celcius */
/*Author:Ayush Kumar Shukla*//*Date-23rd Nov 2021 */
#include<stdio.h>

int main()
{
	float fahr,cel;
	printf("Enter the temperature of your city in fahrenheit: ");
	scanf("%f",&fahr);
	
	cel = (fahr-32)*((float)5/9); // the division 5/9 is not fractional but integral , hence it only returns 0 and not the 0.55555 , and converting the 0(the actual result of division) into a float will give 0.000 and not the desired output
	printf("The Temperature In Degree Celcius Is:%f",cel);
	return 0;	

}

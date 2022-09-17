/*Program to calculate gross salary*/
/*Author - Ayush Kumar Shukla*/ /*Date - 18th Nov 2021*/

#include<stdio.h>

int main()
{
	float basic_salary,dearness_allowance,house_rent_allowance,gross_salary; //create short variable names.
	printf("\nEnter Your Basic Salary: ");
	scanf("%f",&basic_salary)
	dearness_allowance = (0.4 * basic_salary);
	house_rent_allowance = (0.2 * basic_salary);
	
	gross_salary = basic_salary+dearness_allowance+house_rent_allowance;
	printf("Your Dearness Allowance Is %f\n",dearness_allowance);
	printf("Your House Rent Allowance Is %f\n",house_rent_allowance);
	printf("Your Gross Salary is:%f  ",gross_salary );
	
	
	
	return 0;
}

/* Program tofind the area of a triangle */
/*Author: Ayush Kumar Shukla*//*Date:25th Nov 2021*/

#include<stdio.h>
#include<math.h>    
int main()
{
	float a,b,c,sp,area;
	printf("\nEnter the lenghts of the sides of the triangle:");
	scanf("%f%f%f",&a,&b,&c);
	
	sp = (a+b+c)/2;
	area = sqrt(sp*(sp-a)*(sp-b)*(sp-c));
	printf("The area of the given triangle is: %f ",area);
	return 0 ;
	
	
	
}
// Heron's Formula for calculating the area of a triangle with three sides given = sqrt(sp*(sp-a)(sp-b)(sp-c)
// The sqrt function cannot handle negative values

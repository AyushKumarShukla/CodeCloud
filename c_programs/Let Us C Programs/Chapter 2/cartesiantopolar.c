/*Program to convert cartesian coordinates into polar coordinates*/
/*Author: Ayush Kumar Shukla*//*Date:30th November*/

#include<stdio.h>
#include<math.h>

int main()
{
	float x,y,mod,arg;
	printf("Enter the cartesian coordinates (x,y) : ");
	scanf("%f%f",&x,&y);
	
	mod = sqrt(x*x+y*y);
	arg = atan2(y,x);
	
	printf("The polar coordinates are (%f,%f)",mod,arg);
	return 0 ;
	
	
	
	
	
}

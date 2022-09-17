/*Program to calculate the area and perimeter of a rectangle and area and circumference of
a circle */
/*Author:Ayush Kumar Shukla*//*Date-23rd Nov 2021*/

#include<stdio.h>

int main()
{
	float len,wid,rad,rectarea,rectperi,cirarea,circirc,pi;
	printf("Enter the length and width of a rectangle: ");
	scanf("%f%f",&len,&wid);
	printf("Enter the radius of a circle: ");
	scanf("%f",&rad);
	pi = 3.141592653589789323;
	
	rectarea = len * wid;
	rectperi = 2*(len+wid);
	cirarea = pi*rad*rad;
	circirc  = 2*pi*rad;
	
	printf("The area of the rectangle is: %f\n",rectarea);
	printf("The perimeter of the rectangle is: %f\n",rectperi);
	printf("The area of the circle is: %f\n",cirarea);
	printf("The circumference of the circle is: %f\n",circirc);
	return 0 ;
}

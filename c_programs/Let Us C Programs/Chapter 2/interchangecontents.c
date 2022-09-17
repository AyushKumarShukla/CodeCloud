/*Interchanging Variable Content*/

#include<stdio.h>

int main(void)
{
	int c,d,newt;
	printf("Enter two numbers: ");
	scanf("%d%d",&c,&d); 
	newt = c; // preserves the original value of c
	c=d;      // sets the value to c to that of d
	d = newt; // sets the value of d to the original preserved value of c
	printf("C=%d and D=%d",c,d); // contents are interchanged
	return 0;
}

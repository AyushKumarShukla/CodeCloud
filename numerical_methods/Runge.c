#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double eq(double x,double y)
{
	double expr;
	expr=x-y;
	return expr;
}
double secondorder(double initx,double inity,double step,double finx)
{
	int i=1;
	double arg=0,x=initx,y=inity,k1,k2,k,res;
	do
	{
		k1=step*eq(x,y);
		k2=step-(eq(x+step,y+step));
		k=0.5*(k1+k2);
		res=y+k;
		arg=step*i;
	}while(arg!=finx);
	printf("RESULT: %lf",res);	
}
double fourthorder()
{
}


int main(void)
{
	int ch;
	double initx,inity,finx,step;
	printf("To solve the differential equation dy/dx = x-y using Runge-Kutta methods: \n");
	while(1)
	{
		printf("MENU:\n1.Runge Kutta Method of Second Order\n2.Runge Kutta Method of Fourth Order\n3.EXIT");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		printf("Enter initial value of y: ");
		scanf("%lf",&inity);
		printf("Enter initial value of x: ");
		scanf("%lf",&initx);
		printf("Enter final value of x: ");
		scanf("%lf",&finx);
		printf("Enter step length: ");
		scanf("%lf",&step);
		switch(ch)
		{
			case 1:
				secondorder(initx,inity,step,finx);
				break;
			case 2:
				fourthorder();
				break;
			case 3:
				exit(1);
				break;
			default:
				printf("Please enter a valid option from the menu");
		}
	}
}

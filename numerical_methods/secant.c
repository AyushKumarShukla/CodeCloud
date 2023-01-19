#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double x)
{
	double res;
	//res=tan(x)+x;
	res=pow(x,3)+7*pow(x,2)+9;
	return res;
}

double secant(double left,double right)
{
	double xnext,val_left,val_right;
	printf("LEFT\t\tF(LEFT)\t\tRIGHT\t\tF(RIGHT)\tNEXT\n");
	while(1)
	{
		val_left=f(left);
		val_right=f(right);
		xnext = right-f(right) * (right - left) / (f(right) - f(left));
		if(fabs(xnext-right)>0.000001)
		{
			left=right;
			right=xnext;
			printf("%lf\t%lf\t%lf\t%lf\t%lf\n",left,val_left,right,val_right,xnext);
			xnext=0;
		}
		else
			return xnext;
	}
}

void validate(double left,double right)
{
	if(f(left)*f(right)>0)
	{
		printf("No root exists between %lf and %lf\n",left,right);
		exit(1);
	}
}

int main(void)
{
	double left,right,res;
	printf("To find the root of the function x^3 + 7x^2 + 9 = 0 using Secant Method\n");
	printf("Enter a small range of values: ");
	scanf("%lf%lf",&left,&right);
	validate(left,right);
	res=secant(left,right);
	printf("ROOT: %lf\n",res);
}

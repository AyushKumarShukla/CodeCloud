#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define error 1e-6

double f(double x)
{
	return(pow(x,3)-pow(x,2)+2);
}

double fder(double x)
{
	return(3*pow(x,2)+2*x);
}

void check_inp(double *left, double *right)
{
	double temp;
	if(f(*left)*f(*right)>0)
	{
		printf("No real root lies in the given range");
		exit(1);
	}
	else if(fder(*left)*fder(*right)<0)
	{
		printf("The derivative of function changes sign....");
		exit(1);
	}
	else
		printf("One real root exists in the given range");
	
	if(f(*left)<0)
	{
		temp=*right;
		*right=*left;
		*left=temp;
	}
	else if (f(*right)>0)
	{
		temp=*left;
		*left=*right;
		*right=temp;
	}
}

void bisection_method(double left,double right)
{
	double mid;
	while(fabs(left)-fabs(right)>error)
	{
		mid=(left+right)/2;
		if(f(mid)<0)
			right=mid;
		else if(f(mid)>0)
			left=mid;
	}
	printf("Root of the given equation : %.4lf",left);
}

int main(void)
{
	double left,right;
	printf("To find the root of the equation x^3+x^2+2=0\n");
	printf("Enter a small range of values: ");
	scanf("%lf%lf",&left,&right);
	check_inp(&left,&right);
	bisection_method(left,right);	
}

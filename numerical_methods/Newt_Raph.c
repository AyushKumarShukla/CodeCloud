#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double func(double x)
{
    //return (pow(x,3)-x-0.1);
    return (3*x-cos(x)-1);
}

double func_der(double x)
{
    //return (3*pow(x,2)-1);
    return (3+sin(x));
}

double Newton_Raphson(double usr_x)
{
    double x=usr_x,corr=0,fx=0,fdx=0;
    int i=1;
    printf("\nNo.\t  X\t\t  F(X)\t\t  dF(X)\t\t  H\t\t  NEXT X\n");
    do
    {
        fx=func(x);
        fdx=func_der(x);
        corr=-(fx/fdx);
	printf("%d\t%lf\t%lf\t%lf\t%lf\t",i,x,fx,fdx,corr);
        x=x+corr;
	i++;
        printf("%lf\n",x);
    }while(fabs(fx)>=1e-8);
    return x;
}

void validate(double lowl, double uppl)
{
	if(func(lowl)*func(uppl)>=0)
	{
		printf("No root exists between %lf and %lf for the given function \n",lowl,uppl);
		exit(1);
	}
}

int main(void)
{
    double lowl,uppl,res;
    //printf("To find the roots of the equation x^3-x-0.1 = 0 using Newton-Raphson Method : \n");
    printf("To find the roots of the equation 3x-cosx-1 = 0 using Newton-Raphson Method: \n"); 
    printf("Enter a small range of values: \n");
    printf("Enter Lower Limit: ");
    scanf("%lf",&lowl);
    printf("Enter Upper Limit: ");
    scanf("%lf",&uppl);
    validate(lowl,uppl);
    res=Newton_Raphson(lowl);
    printf("\nThe Root of the given equation between %lf and %lf is: %lf\n",lowl,uppl,res);
    return 0;
}

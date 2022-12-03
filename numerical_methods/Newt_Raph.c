#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double func(double x)
{
    return (3*pow(x,3)+5*x-40);
}

double func_der(double x)
{
    return (9*pow(x,2)+5);
}

double Newton_Raphson(double usr_x)
{
    double x=usr_x,corr;
    do
    {
        corr=-(func(x)/func_der(x));
        x=x+corr;
        printf("%lf\n",x);
    }while(func(x)>=1e-8);
    return x;
}

int main(void)
{
    double lowl,uppl,res;
    printf("To find the roots of the equation: \n");
    printf("Enter a small range of values: \n");
    printf("Enter Lower Limit: ");
    scanf("%lf",&lowl);
    printf("Enter Upper Limit: ");
    scanf("%lf",&uppl);
    if(func(lowl)*func(uppl)>=0)
    {
        printf("No root exists in this range:");
        return 0;
    }
    else
    {
        res=Newton_Raphson(lowl);
        printf("Root:%lf",res);
    }
    return 0;
}
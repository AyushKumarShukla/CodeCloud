// program to calculate the integral of a given function using composite trapezoidal rule
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float expression(float x)
{
	float val;
	val = x*x*x;
	return val;
}

float trapezoidal(float low,float high,float divnum)
{
	float steps,first,last,i,sum=0,arg,result;
	steps = ((high-low)/divnum);
	first=expression(low);
	last=expression(high);
	printf("Values Of Other Terms:\n");
	for(i=1;i<=(divnum-1);i++)
	{
		arg=low+(steps*i);
		sum=sum+expression(arg);
		printf("x\t\ty\n");
		printf("%f\t%f\n",arg,sum);
	}
	result=(steps/2)*(first+last+2*sum);
	return result;
}

int main(void)
{
	float low,high,divnum,res;
	printf("To calculate the integral of x^3\n");
	printf("Enter the lower limit: ");
	scanf("%f",&low);
	printf("Enter the higher limit: ");
	scanf("%f",&high);
	printf("Enter the number of divisions: ");
	scanf("%f",&divnum);
	res=trapezoidal(low,high,divnum);
	printf("INTEGRAL:%f",res);
}



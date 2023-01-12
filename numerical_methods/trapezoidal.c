// program to calculate the integral of a given function using composite trapezoidal rule
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float expression(float x)
{
	float val;
	//val = 1/pow((1+x),2);
	val=1/(1+2*x);
	return val;
}

float trapezoidal(float low,float high,float divnum)
{
	float steps,first,last,i,sum=0,arg,result;
	int cnter=0;
	steps = ((high-low)/divnum);
	first=expression(low);
	last=expression(high);
	printf("Table of values of function for each step:\n");
	printf("No.\t\tx\t\t  y=f(x)\n");
	printf("%-10d %-20f %-20f\n",cnter,low,first);
	for(i=1;i<=(divnum-1);i++)
	{
		cnter++;
		arg=low+(steps*i);
		sum=sum+expression(arg);
		printf("%-10d %-20f %-20f\n",cnter,arg,sum);
	}
	printf("%-10d %-20f %-20f\n",cnter+1,high,last);
	result=(steps/2)*(first+last+2*sum);
	return result;
}

int main(void)
{
	float low,high,divnum,res;
	//printf("To calculate the integral of 1/(1+x)^2\n");
	printf("To calculate the integral of 1/(1+2xd)\n");
	printf("Enter the lower limit: ");
	scanf("%f",&low);
	printf("Enter the higher limit: ");
	scanf("%f",&high);
	printf("Enter the number of divisions: ");
	scanf("%f",&divnum);
	res=trapezoidal(low,high,divnum);
	printf("INTEGRAL:%f",res);
	printf("\n");
	return 0;
}



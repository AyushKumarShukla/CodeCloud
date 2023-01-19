#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void getarray(double* arr,int size)
{
	int i;
	for(i=0;i<size;i++)
		scanf("%lf",&arr[i]);
}

double lagrange(double* x, double* y,double val,double num)
{
	int i,j;
	double term,result;
	for(i=0;i<num;i++)
	{
		term=y[i];
		for(j=0;j<num;j++)
		{
			if(i==j)
				continue;
			else
				term=term*((val-x[j])/(x[i]-x[j]));
		}
		result=result+term;
	}
	return result;
}

int main(void)
{
	double x[20],y[20],val,res;
	int num;
	printf("To perform interpolation using Lagrange's Interpolation Formula\n");
	printf("Enter the number of given datapoints: ");
	scanf("%d",&num);
	//input validation
	if(num<=0)
	{
		printf("Invalid Input, Enter a valid number of datapoints\n");
		exit(1);
	}
	printf("Enter the values of x: ");
	getarray(x,num);
	printf("Enter the values of y: ");
	getarray(y,num);
	printf("Enter the value of x at which F(x) is needed: ");
	scanf("%lf",&val);
	res=lagrange(x,y,val,num);
	printf("F(%lf) = %lf\n",val,res);
	return 0;
}

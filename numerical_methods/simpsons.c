// program to calculate the integral of a given function using composite simpsons rule
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float expression(float x)
{
	float val;
	val = x/(1+x);
	return val;
}

float simpsons(float low,float high,float divnum)
{
	float steps,first,last,i,oddsum=0,evensum=0,oddarg,evenarg,result;
	steps = ((high-low)/divnum);
	first=expression(low);
	last=expression(high);
	//loop for odd
	for(i=1;i<divnum;i=i+2)
	{
		oddarg=low+(steps*i);
		oddsum=oddsum+expression(oddarg);
		if(i+1!=divnum)
		{
			evenarg=low+(steps*(i+1));
			evensum=evensum+expression(evenarg);
		}
		printf("x\t\ty\n");
		printf("%f\t%f\n",oddarg,oddsum);
		if(i+1!=divnum)
			printf("%f\t%f\n",evenarg,evensum);
	}
	result=(steps/3)*(first+last+2*evensum+4*oddsum);
	return result;
}

int main(void)
{
	float low,high,divnum,res;
	printf("To calculate the integral of x/(1+x)\n");
	printf("Enter the lower limit: ");
	scanf("%f",&low);
	printf("Enter the higher limit: ");
	scanf("%f",&high);
	printf("Enter the number of divisions: ");
	scanf("%f",&divnum);
	res=simpsons(low,high,divnum);
	printf("INTEGRAL:%f",res);
}



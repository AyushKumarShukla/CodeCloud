#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double eq(double x)
{
	double res;
	res=pow(10,x)+sin(x)+2*x;
	//printf("%lf\n",res);
	return res;
}

void validate(double left,double right)
{
	double check;
	check = eq(left)*eq(right);
	if(check>0)
	{
		printf("No root exists between %lf and %lf",left,right);
		exit(1);
	}
}

double bisection(double left,double right,double error)
{
	int i=0;
	double mid=0,val;
	printf("______________________________________________________________________________\n");
	printf("  NO\t   X\t\t   Y\t\t   MID\t\t   F(MID)\n");
	printf("______________________________________________________________________________\n");
	while(fabs(left-right)>error)
	{
		mid=(left+right)/2;
		if(eq(mid)==0)
		{
			printf("%lf is root",mid);
			break;
		}
		else
		{
			val=eq(mid);
			if(val>0)
			{
				if(eq(left)>0)
					left=mid;
				else
					right=mid;
			}
			else
			{
				if(eq(left)<0)
					left=mid;
				else
					right=mid;
			}
		}
		printf("| %d\t|%lf\t|%lf\t|%lf\t|%lf\t|\n",i,left,right,mid,val);
		i++;
	}
	return mid;
}

int main(void)
{
	double left,right,error,mid,res;
	error=0.0000001;
	printf("To find the root of 10^x + sinx + 2x = 0 using Bisection method\n");
	printf("Enter the left limit: ");
	scanf("%lf",&left);
	printf("Enter the right limit: ");
	scanf("%lf",&right);
	validate(left,right);
	res=bisection(left,right,error);
	printf("\nResult:%lf\n",res);
	return 0;
}

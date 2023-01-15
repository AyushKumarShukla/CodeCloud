#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double func(double x)
{
	double res=0;
	res=sin(x)+cos(x)-1;
	return res;
}

void range_input(double* lowl, double* uppl)
{
	printf("\nLower Limit:");
	scanf("%lf",lowl);
	printf("Upper Limit:");
	scanf("%lf",uppl);
}

double reg_falsi(double lowl,double uppl)
{
	double corr=0,val_low,val_upp,val_corr,next=0,prev_next;
	int i=1;
	printf("No.\tA\tB\t  F(A)\t      F(B)\tH   \t  NEXT\t   F(NEXT)\n");
	do
	{
		val_low=func(lowl);
		val_upp=func(uppl);
		corr=(fabs(val_low)*(uppl-lowl))/(fabs(val_low)+fabs(val_upp));
		prev_next=next;
		next=lowl+corr;
		printf("%d    %lf  %lf  %lf  %lf  %lf  %lf  %lf\n",i,lowl,uppl,func(lowl),func(uppl),corr,next,func(next));
		//printf("\nA\t\tB\tF(A)\t\t\tF(B)\t\t\tH\t\t\tNEXT\t\t\tF(NEX8T)");
		//printf("\n%lf\t%lf\t%lf\t%lf|",lowl,uppl,val_low,val_upp);
		if(func(next)<0)
		{
			if(val_low<0)
				lowl=next;
			else
				uppl=next;
		}
		else
		{
			if(val_low>=0)
				lowl=next;
			else
				uppl=next;
		}
		i++;
	}while(fabs(next-prev_next)>1e-7);
	return next;
}

int main(void)
{
	double lowl,uppl,root;
	printf("To find the root of the equation sinx + cosx - 1 = 0 using Regula Falsi method:\n");
	printf("Enter a small range of values: ");
	range_input(&lowl,&uppl);
	//printf("%lf%lf",lowl,uppl);
	root=reg_falsi(lowl,uppl);
	printf("\nRoot is %lf\n",root);
	return 0;

}

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
	
	do
	{
		val_low=func(lowl);
		val_upp=func(uppl);
		corr=(fabs(val_low)*(uppl-lowl))/(fabs(val_low)+fabs(val_upp));
		prev_next=next;
		next=lowl+corr;
//		printf("\nA\t\tB\tF(A)\t\t\tF(B)\t\t\tH\t\t\tNEXT\t\t\tF(NEX8T)");
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
		printf("\t%lf\t%lf\t%lf\n",corr,next,func(next));
	}while(fabs(next-prev_next>1e-7));
	return next;
}

int main(void)
{
	double lowl,uppl,root;
	printf("Enter a small range of values: ");
	range_input(&lowl,&uppl);
	//printf("%lf%lf",lowl,uppl);
	root=reg_falsi(lowl,uppl);
	printf("\nRoot is %lf",root);
	return 0;

}

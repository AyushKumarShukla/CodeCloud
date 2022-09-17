/*Profit or loss*/

#include<stdio.h>

int main(void)
{
	int costp,sellp,prof,loss;
	printf("Enter the cost price: ");
	scanf("%d",&costp);
	printf("Enter the sale price: ");
	scanf("%d",&sellp);
	
	prof = sellp-costp;
	loss = costp-sellp;
	
	if(prof>0)
		printf("PROFIT:%drs",prof);
	if(loss>0)
		printf("LOSS:%drs",loss);
	if(prof==loss)
		printf("NEUTRAL EXCHANGE");
	return 0;

	return 0;
	
}

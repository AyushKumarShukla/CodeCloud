/*Program to find smallest number of denomination to amount to a sum of money*/
/*Author: Ayush Kumar Shukla*//*Date:29th Novemeber 2021*/
// In the % operator the remainder is not the decimal value of the division , it is actually the remaining part that cannot be furthur divided by the divisor integrally

#include<stdio.h>

int main(void)
{
	int amount,hun,fif,ten,fiv,two,one,numnotes;
	printf("Enter the amount: ");
	scanf("%d",&amount);
	
	hun=amount/100;
	amount=amount%100;
	fif=amount/50;
	amount=amount%50;
	ten=amount/10;
	amount=amount%10;
	fiv=amount/5;
	amount=amount%5;
	two = amount/2;
	amount=amount%2;
	one = amount/1;
	
	numnotes = hun+fif+ten+fiv+two+one;
	printf("Number of Notes: %d",numnotes);
	return 0;
	
	
	
	
	}	
		
	
	
	
	


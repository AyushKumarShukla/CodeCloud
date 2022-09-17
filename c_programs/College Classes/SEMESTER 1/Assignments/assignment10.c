/*WAP in C to find the HCF and LCM of two given numbers*/

#include<stdio.h>

void hcf(int num1, int num2)
{
	int i,hcf=1,lcm;
	for(i=1;i<=num2;i++)
	{
		if(num1%i==0)
			if(num2%i==0)
				if(i>hcf)
					hcf=i;
				
	}
	lcm=(num1*num2)/hcf;
	printf("HCF:%d",hcf);
	printf("\nLCM:%d",lcm);
	return;
}



int main(void)
{
	int num1,num2;
	printf("TO CALCULATE HCF AND LCM OF TWO NUMBERS \n");
	printf("ENTER TWO NUMBERS: ");
	scanf("%d%d",&num1,&num2);
	
	hcf(num1,num2);
	return 0;
}

/*OUTPUT
SET 1:
TO CALCULATE HCF AND LCM OF TWO NUMBERS
ENTER TWO NUMBERS: 16 32
HCF:16
LCM:32
--------------------------------
Process exited after 6.454 seconds with return value 0
Press any key to continue . . .

SET 2:
TO CALCULATE HCF AND LCM OF TWO NUMBERS
ENTER TWO NUMBERS: 54 87
HCF:3
LCM:1566
--------------------------------
Process exited after 1.92 seconds with return value 0
Press any key to continue . . .

SET 3:
TO CALCULATE HCF AND LCM OF TWO NUMBERS
ENTER TWO NUMBERS: 52 40
HCF:4
LCM:520
--------------------------------
Process exited after 2.863 seconds with return value 0
Press any key to continue . . .
*/



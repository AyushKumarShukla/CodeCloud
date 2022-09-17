/*Trigonometric ratios for a given angle*/
#include<math.h>
#include<stdio.h>

int main(void)
{
	float ang,nsin,ncos,ntan,ncosec,nsec,ncot;
	printf("Enter the angle: ");
	scanf("%d",&ang);
	
	nsin = sin(ang);
	ncos = cos(ang);
	ntan = nsin/ncos;
	ncosec = 1.0/nsin;
	nsec = 1.0/ncos;
	ncot = 1.0/ntan;
	
	printf("sinx = %f\n cosx = %f\n tanx = %f\n cosecx = %f\n secx = %f\n cotx = %f\n",nsin,ncos,ntan,ncosec,nsec,ncot);
	return 0;
	
}

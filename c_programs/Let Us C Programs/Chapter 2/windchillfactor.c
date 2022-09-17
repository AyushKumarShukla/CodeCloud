/*Wind chill factor computation*/

#include<stdio.h>
#include<math.h>
int main(void)
{
	int wcf,temp,vel;
	printf("Enter the air temperature(in degree celcius): ");
	scanf("%d",&temp);
	printf("Enter the wind velocity(in miles per hour): ");
	scanf("%d",&vel);
	
	wcf= 35.74 + 0.6215*temp+(0.427*temp-35.75)*pow(vel,0.16);
	printf("WIND CHILL FACTOR: %d",wcf);
	return 0;
}

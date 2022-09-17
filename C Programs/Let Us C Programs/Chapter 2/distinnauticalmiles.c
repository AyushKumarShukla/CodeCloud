/*Distance in nautical miles form latitude and longitude*/

#include<stdio.h>
#include<math.h>

int main(void)
{
	int l1,l2,g1,g2,d;
	printf("Enter the latitude of both the places: ");
	scanf("%d%d",&l1,&l2);
	printf("Enter the longitude of both the places: ");
	scanf("%d%d",&g1,&g2);
	
	d = 3963*acos(sin(l1)*sin(l2)+cos(l1)*cos(l2)*cos(g2-g1));
	printf("DISTANCE IN NAUTICAL MILES: %d",d);
	return 0;
}

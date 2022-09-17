/*paper size teller using loops*/
/*Author:Ayush Kumar Shukla*//*Date:23rd Nov 2021*/

#include<stdio.h>

int main()
{
	int len=1189,wid=841,i=1,n,newlen,newwid,size=1;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	
	while(i<=n)
	{
		newlen=wid;
		newwid=len/2;
		printf("Dimesions of A%d are %dmm x %dmm \n",size,newlen,newwid);
		size = size+1;
		i = i+1;
		len = newlen;
		wid = newwid;

	}
	return 0 ;
	
	
	
	
}

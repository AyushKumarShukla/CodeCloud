/*Write a program in C to print a triangle of stars as follows (take number of lines from user):

     *
    ***
   *****
  *******
 *********
*/

#include<stdio.h>

int main(void)
{
	int num,i,j;
	printf("Enter the numWber of lines needed: ");
	scanf("%d",&num);

	for(i=1;i<=num;i++)
	{
		for(j=1;j<=(2*num-1);j++)
		{
			if( j>=num-(i-1) && j<=num+(i-1))
			{
				printf("*");
			}
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
/*
OUTPUT:

SET 1:
Enter the number of lines needed: 5
    *
   ***
  *****
 *******
*********

--------------------------------
Process exited after 14.3 seconds with return value 0
Press any key to continue . . .

SET 2:
Enter the number of lines needed: 6
     *
    ***
   *****
  *******
 *********
***********

--------------------------------
Process exited after 1.225 seconds with return value 0
Press any key to continue . . .

SET 3:
Enter the number of lines needed: 10
         *
        ***
       *****
      *******
     *********
    ***********
   *************
  ***************
 *****************
*******************

--------------------------------
Process exited after 1.825 seconds with return value 0
Press any key to continue . . .
*/





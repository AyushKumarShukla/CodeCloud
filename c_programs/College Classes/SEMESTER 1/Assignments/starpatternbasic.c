/*WAP in C to print the following pattern	*
											***
											*****
											*******
											*********
*/

#include<stdio.h>

int main(void)
{
	int num,i,j;
	printf("Enter the number of lines: ");
	scanf("%d",&num);
	
	for(i=1;i<=num;i++) // determines number of lines
	{
	 for(j=1;j<=i;j++) // determines the elements in each line
	 {
	 	printf("*");
   	 }	
   	 printf("\n");
	}	
	return 0;
}

/*OUTPUT
SET 1:
Enter the number of lines: 5
*
**
***
****
*****

--------------------------------
Process exited after 10.98 seconds with return value 0
Press any key to continue . . .

SET 2:
Enter the number of lines: 18
*
**
***
****
*****
******
*******
********
*********
**********
***********
************
*************
**************
***************
****************
*****************
******************

--------------------------------
Process exited after 1.361 seconds with return value 0
Press any key to continue . . .


SET 3:
Enter the number of lines: 9
*
**
***
****
*****
******
*******
********
*********

--------------------------------
Process exited after 1.106 seconds with return value 0
Press any key to continue . . .*/

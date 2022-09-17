/*WAP in C to print the following star pattern: 	*
												  ***
												*****
											  *******
										    *********

*/

#include<stdio.h>

int main(void)
{
	int num,i,j;
	printf("Enter the number of rows: ");
	scanf("%d",&num);
	
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			if(i+j>=num-1)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
	
}




/*
OUTPUT

SET 1:
Enter the number of rows: 5
    *
   **
  ***
 ****
*****

--------------------------------
Process exited after 1.074 seconds with return value 0
Press any key to continue . . .

SET 2:
Enter the number of rows: 6
     *
    **
   ***
  ****
 *****
******

--------------------------------
Process exited after 1.632 seconds with return value 0
Press any key to continue . . .

SET 3:
Enter the number of rows: 10
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

--------------------------------
Process exited after 1.231 seconds with return value 0
Press any key to continue . . .
*/

/*Write a program in C to print a triangle of stars as follows (take number of lines from user):

*	       *
**	      **
***	     ***
****	****
*****  *****
************
*/


#include<stdio.h>

int main(void)
{
    int num,i,j;
    printf("Enter the number of lines required: ");
    scanf("%d",&num);

    for(i=1;i<=num;i++)
    {
        for(j=1;j<=(2*num-1);j++)
        {
            if(j<=i || j>=(2*num)-i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}

/*
OUTPUT:
Enter the number of lines required: 5

SET 1:

*       *
**     **
***   ***
**** ****
*********

--------------------------------
Process exited after 2.159 seconds with return value 0
Press any key to continue . . .

SET 2:
Enter the number of lines required: 7
*           *
**         **
***       ***
****     ****
*****   *****
****** ******
*************

--------------------------------
Process exited after 2.896 seconds with return value 0
Press any key to continue . . .

SET 3:
Enter the number of lines required: 12
*                     *
**                   **
***                 ***
****               ****
*****             *****
******           ******
*******         *******
********       ********
*********     *********
**********   **********
*********** ***********
***********************

--------------------------------
Process exited after 2.515 seconds with return value 0
Press any key to continue . . .
*/

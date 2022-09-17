/*WAP in C to print the following pattern:  1
											01
											101
											0101
											10101
											010101
											1010101
*/

#include<stdio.h>

int main(void)
{
	int num,ele,i,j;
	printf("Enter the number of lines needed: ");
	scanf("%d",&num);

	for(i=1;i<=num;i++)
	{
		for(j=i;j>=1;j--) // begins the loop counter from the larger value of i and decreases till it is 1
		{
			printf("%d",j%2);
		}
		printf("\n");
	}


	return 0;
}

/*
OUTPUT:
SET 1:
Enter the number of lines needed: 5
1
01
101
0101
10101

--------------------------------
Process exited after 2.215 seconds with return value 0
Press any key to continue . . .

SET 2:
Enter the number of lines needed: 6
1
01
101
0101
10101
010101

--------------------------------
Process exited after 1.855 seconds with return value 0
Press any key to continue . . .

SET 3:
Enter the number of lines needed: 4
1
01
101
0101

--------------------------------
Process exited after 1.52 seconds with return value 0
Press any key to continue . . .
*/






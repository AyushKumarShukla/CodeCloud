/*Write a program in C to check whether a given year is a leap year or not*/


#include<stdio.h>
#include<stdbool.h>

bool isleapyear(int);

int main(void)
{
	int year;
	printf("Enter the value of year: ");
	scanf("%d",&year);
	if(year<1200 || year>9999)
		{
			printf("INVALID YEAR");
			return 0;
		}
	if (isleapyear(year))
		printf("The given year %d is a leap year",year);
	else
		printf("The given year %d is not a leap year",year);
	return 0;
}

bool isleapyear(int year)
{
	if((year%400==0)||(year%100!=0 && year%4==0))
		return true;
	else
		return false;
}

/*OUTPUT:

SET 1:
Enter the value of year: 2003
The given year 2003 is not a leap year
--------------------------------
Process exited after 1.715 seconds with return value 0
Press any key to continue . . .

SET 2:
Enter the value of year: 2024
The given year 2024 is a leap year
--------------------------------
Process exited after 4.37 seconds with return value 0
Press any key to continue . . .

SET 3:
Enter the value of year: 2000
The given year 2000 is a leap year
--------------------------------
Process exited after 1.467 seconds with return value 0
Press any key to continue . . .

SET 4:
Enter the value of year: 1100
INVALID YEAR
--------------------------------
Process exited after 1.984 seconds with return value 0
Press any key to continue . . .

SET 5:
Enter the value of year: 987455
INVALID YEAR
--------------------------------
Process exited after 2.507 seconds with return value 0
Press any key to continue . . .

*/

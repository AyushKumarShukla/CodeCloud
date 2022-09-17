/*Write a program in C to display the fibonacci sequence of first n natural numbers*/

#include<stdio.h>

void fibo(int num)
{
	int i,num1=0,num2=1,sum=0;
	printf("0 1 ");
	for(i=1;i<=num-2;i++)
	{
		sum = num1 + num2;
		num1=num2;
		num2=sum;
		printf("%d ",sum);
	}
	return ;
}

int main(void)
{
	int num;
	printf("To display the fibonacci sequence\n");
	printf("Enter the number of terms: ");
	scanf("%d",&num);
	fibo(num);
	return 0;
}

/*
OUTPUT
SET 1:
To display the fibonacci sequence
Enter the number of terms: 5
0 1 1 2 3
--------------------------------
Process exited after 2.892 seconds with return value 0
Press any key to continue . . .

SET 2:
To display the fibonacci sequence
Enter the number of terms: 10
0 1 1 2 3 5 8 13 21 34
--------------------------------
Process exited after 1.676 seconds with return value 0
Press any key to continue . . .

SET 3:
To display the fibonacci sequence
Enter the number of terms: 9
0 1 1 2 3 5 8 13 21
--------------------------------
Process exited after 4.226 seconds with return value 0
Press any key to continue . . .*/


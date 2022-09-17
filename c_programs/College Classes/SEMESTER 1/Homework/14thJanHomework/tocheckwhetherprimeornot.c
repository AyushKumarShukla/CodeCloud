#include<stdio.h>
#include<math.h>
int main(void)
{
    int num,i,flag=0;
    printf("To check primality");
    printf("\nEnter a number: ");
    scanf("%d",&num);

    for(i=2;i<=sqrt(num);i++)
        if(num%i==0)
        {
            flag=1;
            break;
        }
    if(flag==0)
        printf("%d is prime",num);
    else
        printf("%d is not prime",num);
    return 0;
}

/*
OUTPUT
To check primality
Enter a number: 89
89 is prime
--------------------------------
Process exited after 3.903 seconds with return value 0
Press any key to continue . . .
*/

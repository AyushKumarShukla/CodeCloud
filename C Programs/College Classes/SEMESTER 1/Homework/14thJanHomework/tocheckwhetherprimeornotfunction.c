/*To check whether a given number is prime or not*/

#include<stdbool.h>
#include<stdio.h>
#include<math.h>

bool isprime(int num)
{
    int i,flag=0;
    for(i=2;i<=sqrt(num);i++)
        if(num%i==0)
        {
            return false;
            break;
        }
        else
            return true;

}

int main(void)
{
    int num;
    printf("To check primality\n");
    printf("Enter a number: ");
    scanf("%d",&num);
    printf("%d",isprime(num));
    if(isprime(num))
        printf("%d is prime",num);
    else
        printf("%d is not prime",num);
    return 0;
}

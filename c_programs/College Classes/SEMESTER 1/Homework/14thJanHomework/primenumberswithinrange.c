/*WAP in C to print all the prime numbers within a given range*/

#include<stdio.h>
#include<math.h>
#include<stdbool.h>

bool isprime(int num)
{
    int i;
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
    int lowl,uppl,i;
    printf("To print all prime numbers within a range: \n");
    printf("Enter a lower and upper limit: ");
    scanf("%d%d",&lowl,&uppl);

    for(i=lowl;i<=uppl;i++)
        if(isprime(i))
            printf("%d ",i);
    return 0;
}
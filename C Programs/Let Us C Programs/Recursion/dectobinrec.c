#include<stdio.h>
#include<stdlib.h>

void dectobin(int num)
{
    int rem;
    if(num==0)
        return;
    elses
    {
        rem=num%2;
        dectobin(num/2);
    }
    printf("%d ",rem);
}

int main(void)
{
    int num;
    printf("Enter a integer: ");
    scanf("%d",&num);
    dectobin(num);
}
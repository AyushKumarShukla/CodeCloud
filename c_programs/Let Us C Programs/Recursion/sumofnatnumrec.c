#include<stdio.h>
#include<stdlib.h>

int sumnatrec(int num,int terms)
{
    int sum;
    if(terms>0)
        sum=num+(sumnatrec(num+1,terms-1));
    else
        return 0;
    return sum;
}
int main(void)
{
    int terms,sum,num=1;
    printf("To print the sum of natural numbers: ");
    printf("Enter the number of terms needed: ");
    scanf("%d",&terms);
    sum=sumnatrec(num,terms);
    printf("SUM:%d",sum);
    return 0;
}
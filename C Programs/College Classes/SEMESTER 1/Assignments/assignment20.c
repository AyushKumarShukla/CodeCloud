/*WAP in C to implement exp(x)*/


#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int digits(int usrnum)
{
    int count=0,num,i;
    num=usrnum;
    while(num>0)
    {
        num = num/10;
        count++;
   }
   return count;
}

int fact(int num)
{
    int product=1,i;
    for(i=num;i>=1;i--)
    {
        product = product * i;
    }
    printf("Fact Term:%d\n",product); 
    return product;
}

int main(void)
{
    float term,num,i=1,exp=0,sum=0;
    printf("enter the power of e you want to calculate: ");
    scanf("%f",&num);

    while(1)
    {
        sum = sum + (float)pow(num,exp)/fact(exp);
        if(digits(sum)>5)
            break;
        i++;
        exp++;
        printf("TEST sum:%f\n",sum);
    }
    printf("Sum of series: %f",sum);
    return 0;
}

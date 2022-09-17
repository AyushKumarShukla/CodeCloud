/*WAP in C to check whether a given number is armstrong or not*/

#include<stdio.h>
#include<math.h>
int main(void)
{
    int usrnum,num,count=0,digit,sum=0;
    printf("To check whether a number is armstrong or not: ");
    printf("\nEnter a number: ");
    scanf("%d",&usrnum);
    num=usrnum;
    //counting the digits
    while(num>0)
    {
        count++;
        num=num/10;
    }
    //calculation
    num=usrnum;
    while(num>0)
    {
        digit=num%10;
        sum=sum+pow(digit,count);
        num=num/10;
    }
    if(sum==usrnum)
        printf("%d is an armstrong number",usrnum);
    else
        printf("%d is not an armstrong number",usrnum);
    return 0;


}
/*
OUTPUT
To check whether a number is armstrong or not:
Enter a number: 98
98 is not an armstrong number
--------------------------------
Process exited after 4 seconds with return value 0
Press any key to continue . . .*/

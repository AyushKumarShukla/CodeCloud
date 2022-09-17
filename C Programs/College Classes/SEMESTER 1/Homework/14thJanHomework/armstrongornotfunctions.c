/*WAP in C to check whether a given number is armstrong or not
using functions*/

#include<stdio.h>
#include<math.h>
#include<stdbool.h>

bool isarmstrong(int usrnum)
{
    int num,digit,count=0,sum=0;
    num=usrnum;
    //counting the digits
    while(num>0)
    {
        count++;
        num = num/10;
    }
    num=usrnum;
    //calculation
    while(num>0)
    {
      digit=num%10;
      sum=sum+pow(digit,count);
      num=num/10;  
    }
    if(sum==usrnum)
        return true;
    else
        return false;

}

int main(void)
{
    int usrnum;
    printf("To check whether a number is armstrong or not: ");
  

    //input validation
    while(1)
    {       
        printf("\nEnter a number: ");
        scanf("%d",&usrnum); 
        if(usrnum<0)       
        {    printf("The input cannot be negative-Try again ");
             printf("To exit-press e");
        }
        else if(usrnum=="e")
            break;
        else
            break;
    }



    if(isarmstrong(usrnum))
        printf("%d is an armstrong number",usrnum);
    else
        printf("%d is not an armstrong number",usrnum);
    return 0;
}
/*
OUTPUT
To check whether a number is armstrong or not:
Enter a number: 153
153 is an armstrong number
--------------------------------
Process exited after 8.067 seconds with return value 0
Press any key to continue . . .*/

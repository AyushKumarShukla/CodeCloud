/*WAP in C to print all the armstrong numbers within a given range*/

#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool isarmstrong(int usrnum)
{
    int num,i,sum=0,count=0,digit;
    num=usrnum;
    //counting the digits
    while(num>0)
        {
            count++;
            num=num/10;
        }
    num=usrnum;
    //calculation 
    while(num>0)
    {
        digit=num%10;
        sum += pow(digit,count);
        num=num/10;
    }
    if(sum==usrnum)
        return true;
    else
        return false;
}


int main(void)
{
    int lowl,uppl,i;
    printf("To print the armstrong number within a given range: ");
    printf("\nEnter the lower limit: ");
    scanf("%d",&lowl);
    printf("\nEnter the upper limit: ");
    scanf("%d",&uppl);

    printf("\nThe armstrong numbers between %d and %d are:",lowl,uppl);
    for(i=lowl;i<=uppl;i++)
        if(isarmstrong(i))
            printf("%d ",i);
    return 0;
}

/*
OUTPUT
To print the armstrong number within a given range:
Enter the lower limit: 1

Enter the upper limit: 1000

The armstrong numbers between 1 and 1000 are:1 2 3 4 5 6 7 8 9 153 370 371 407
--------------------------------
Process exited after 6.927 seconds with return value 0
Press any key to continue . . .
*/

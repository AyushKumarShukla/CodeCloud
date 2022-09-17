/*22. Write a program in C to convert a given Decimal number to its corresponding Roman number*/

#include<stdio.h>

int main(void)
{
    int usrnum,num,nothou,nofivehun,nohun,nofif,noten,nofiv,thou,fivehun,hun,fif,ten,fiv,result;
    printf("To convert a decimal number into Roman Numerals\n");
    printf("Enter a number: ");
    scanf("%d",&usrnum);
    num = usrnum;

    while(num>0)
    {
        nothou=num/1000;
        printf("");
        num=num%1000;
        nofivehun=num/500;
        num=num%500;
        nohun=num/100;
        num=num%100;
        nofif=num/50;
        num=num%50;
        noten=num/10;
        num=num%10;
        nofiv=num/5;
        num=num%5;
    }

    
    result=nothou + nofivehun + nohun + nofif + noten + nofiv;
    printf("ROMAN NUMERAL: %d",result);
    return 0;


}
/*C program to print a string character by character*/

#include<stdio.h>

void xputs(char *p1)
{
    int i;
    for(i=0;p1[i]!='\0';i++)
        putchar(p1[i]); // putchar function prints one character
}

int main(void)
{
    char str1[20];
    xputs("Enter a string: ");
    fgets(str1,19,stdin);
    xputs(str1);
    return 0;
}
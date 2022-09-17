/*WAP in C to open and read a file*/

#include<stdio.h>

int main(void)
{
    FILE *ptr;
    char ch;
    ptr=fopen("hello.txt","r");
    while(1)
    {
        ch=fgetc(ptr);
        if(ch==EOF)
            break;
        putchar(ch);
    }
    return 0;
}
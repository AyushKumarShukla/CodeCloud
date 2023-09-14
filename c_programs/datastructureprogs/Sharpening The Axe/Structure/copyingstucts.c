/*Copying Stuctures*/

#include<stdio.h>
#include<string.h>

int main(void)
{
    typedef struct book
    {
        char title[20];int pages;
    }book;

    book b1={ "AYUSH",576 };
    book b2;
    strcpy(b2.title,b1.title);
    b2.pages=b1.pages;
    printf("%s%i",b2.title,b2.pages);
    return 0;
}
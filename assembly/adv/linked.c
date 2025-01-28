#include<stdio.h>

extern int add(int,int);

int add(int a,int b)
{
    printf("C Linked To ASM!!!!");
    return a+b;
}

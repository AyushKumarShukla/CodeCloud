/*WAP in C to take your own name as input and print it*/

#include<stdio.h>

int main(void)
{
    char name[50];
    printf("Enter Your Name: ");
    fgets(name,50,stdin);
    printf("NAME:%s",name);
    return 0;
}
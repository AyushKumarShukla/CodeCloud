#include<stdio.h>

int main(void)
{
    int ch;
    printf("Enter: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("1");
        default:
            printf("HELLO!");
    }
}
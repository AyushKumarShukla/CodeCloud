#include<stdio.h>

int main(void)
{
    int x=10,*ptr;
    ptr=&x;
    printf("Address of x:%u",&x);
    printf("\n%d",ptr[0]);
    printf("\n%d",&ptr[0]);
    printf("\n%u",&*(ptr+0));
    return 0;
}
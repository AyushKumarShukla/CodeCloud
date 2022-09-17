#include<stdio.h>

int main(void)
{
    int x=10,*ptr;
    ptr=&x;
    ptr[1]=20;
    printf("Address of x:%u",&x);
    printf("\n%d",*(ptr+0));
    return 0;
}
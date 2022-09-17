/*Studying Segmentation Fault*/

#include<stdio.h>
void b(void);
void a(void) //Called function
{
    printf("I am In a!\n");
    b();
    printf("I am back to a\n");
}

void b(void)
{
    printf("I am in b!\n");
    return;
}

int main(void) // Caller function
{
    printf("I am In Main!\n");
    a();
    printf("I am back in main!\n");
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

typedef struct term
{
    int coeff;
    int pow;
}term;

void show(term *arr)
{
    printf("%d",arr[0].coeff);
    printf(" %d",arr[0].pow);
}
int main(void)
{
    term *arr=(term*)malloc(sizeof(term));
    arr[0].coeff=1;
    arr[0].pow=2;
    show(arr);
}
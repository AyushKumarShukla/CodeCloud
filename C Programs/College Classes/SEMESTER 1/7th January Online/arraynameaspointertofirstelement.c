#include<stdio.h>

int main(void)
{
    int arr[5] = {1,2,3,4,5};

    printf("%u\n",&arr[1]);
    printf("%u\n",arr+1); // arr is a pointer to arr[0]

    printf("%d\n",arr[0]);
    printf("%d\n",*(arr+0));
}
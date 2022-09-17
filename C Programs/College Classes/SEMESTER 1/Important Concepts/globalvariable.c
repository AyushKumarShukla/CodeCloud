#include<stdio.h>

int x=0;/*Global variable is a variable that is not defined
within the bounds of any function - Such a variable is
accessible to all the functions in a program*/

void a(void)
{
    x++;
    printf("%d\n",x);
    main();
}

int main(void)
{
    x++;
    printf("%d\n",x);
    a();
}
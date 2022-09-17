/*Studying Segmentation Fault*/

#include<stdio.h>

void func(void)
{
    printf("Hello JWST!\n");
    main();
} // Ending brace never encountered in either function
    // Neither any return statement is there

int main(void)
{
    printf("Hello Earth!\n");
    func();
}
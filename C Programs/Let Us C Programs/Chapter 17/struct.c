/*Basics Of Structures*/

#include<stdio.h>

int main(void)
{
    struct book
    {
        char name[20];;float price;int pages;
    };
    struct book b1,b2,b3;
    printf("Enter the name,price and no pages of 3 books:\n");
    scanf("%s%f%d",b1.name,&b1.price,&b1.pages);
    fflush(stdin); // Make sure to clear the input buffer
    scanf("%s%f%d",b2.name,&b2.price,&b2.pages);
    fflush(stdin);
    scanf("%s%f%d",b3.name,&b3.price,&b3.pages);
    printf("You Entered: \n");
    printf("%c %f %d\n",b1.name,b1.price,b1.pages);
    printf("%c %f %d\n",b2.name,b2.price,b2.pages);
    printf("%c %f %d",b3.name,b3.price,b3.pages);
    return 0;


}
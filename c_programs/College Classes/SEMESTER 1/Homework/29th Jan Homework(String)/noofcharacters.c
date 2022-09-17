/*WAP in C to take a string and print the
number of characters in it*/

#include<stdio.h>
#include<string.h>

int main(void)
{
    int i;
    char name[50];
    printf("Enter your name: ");
    fgets(name,50,stdin);
    name[strlen(name)-1]='\0'; // Eliminating the line feed and replacing it with a null character
    
    //Checking the elements of string
    printf("\n");
    printf("ASCII VALUES OF ELEMENTS:");
    for(i=0;name[i]!='\0';i++)
        printf("%d ",name[i]);

    printf("\nThe number of characters:%d",strlen(name));//Excluding '\n',including blank spaces
    return 0;

}
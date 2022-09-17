/*WAP in C to read the content of a file and print the number of occurence
of each alphabet(A-Z), uppercase and lowercase both should be counted*/

#include<stdio.h>

int main(void)
{
    FILE *fp;
    char ch;
    fp=fopen("text.txt","r");
    //Checking if file is opened
    if(fp==NULL)
    {
        printf("File could not be opened");
        return 1;
    }

    while(1)
    {
        ch=fgetc(fp);
        printf("%c",ch);
        if(ch==EOF)
            break;
    }
    return 0;
}
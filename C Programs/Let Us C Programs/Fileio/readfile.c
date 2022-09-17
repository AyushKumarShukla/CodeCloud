#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    FILE *fp;
    char ch;
    fp=fopen("file.txt","r"); 
    if(fp==NULL)
    {
        printf("Unable to open file");
        exit(1);
    }
    while(1)
    {
        ch=fgetc(fp);
        if(ch==EOF)
            break;
        printf("%c",ch);
    }
    fclose(fp);
    return 0;
}
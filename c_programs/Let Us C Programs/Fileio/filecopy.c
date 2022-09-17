#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    FILE *fs,*ft;
    char ch;
    fs=fopen("file.txt","r");
    ft=fopen("file2.txt","w");
    if(fs==NULL)
    {
        printf("Unable to open source file");
        exit(1);
    }
    if(ft==NULL)
    {
        printf("Unable to open target file");
        exit(2);
    }
    while(1)
    {
        ch=fgetc(fs);
        if(ch==EOF)
            break;
        fputc(ch,ft);
    }
    printf("File Copied Successfully!");
    fclose(fs);fclose(ft);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    FILE *fp;
    int noc=0,nos=0,not=0,nol=0;
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
        noc++;
        if(ch==' ')
            nos++;
        else if(ch=='\n')
            nol++;
        else if(ch=='\t')
            not++;
    }
    printf("\nNumber Of Characters: %d",noc);
    printf("\nNumber Of Lines: %d",nol+1);
    printf("\nNumber Of Spaces: %d",nos);
    printf("\nNumber Of Tabs: %d",not);
    fclose(fp);
    return 0;
}   
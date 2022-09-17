/*WAP in C to open and write in a file*/
#include<stdio.h>
#include<string.h>

int main(void)
{
    FILE *p;
    char str[50],inpstr[50];
    int i=0;
    
    p=fopen("hello.txt","w");
    if(p==NULL)
    {
        printf("FILE COULD NOT BE OPENED!");
        return 1;
    }

   
    while(1)
    {
        printf("Enter:\n");
        gets(str);
        if(strlen(str)==0)
            break;
        fprintf(p,"s",str);
        fprintf(p,"%s","\n");
        i++;
    }  
    fclose(p);
    return 0;

}
/*strcpy implementation*/

#include<stdio.h>

int xstrlen(char* ptr)
{
    int i=0;
    while(ptr[i]!='\0')
        i++;
    return i;
}

void xstrcpy(char *ptr2,char *ptr1)
{
    int i;
    for(i=0;ptr1[i]!='\0';i++)
        ptr2[i]=ptr1[i];
    ptr2[i]='\0';
}

int main(void)
{
    char str1[20],str2[20],i;
    puts("Enter a string: ");
    fgets(str1,19,stdin);
    str1[xstrlen(str1)-1]='\0';
    xstrcpy(str2,str1);
    puts("Copied String: ");
    puts(str2);
    return 0;
    
}
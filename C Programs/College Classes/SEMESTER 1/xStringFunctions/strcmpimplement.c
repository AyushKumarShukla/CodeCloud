/*Using strcmp*/

#include<stdio.h>
#include<string.h>
#include<stdio.h>

int xstrlen(char* ptr)
{
    int i=0;
    while(ptr[i]!='\0')
        i++;
    return i; 
}

int main(void)
{
    char str1[30],str2[30];
    puts("Enter first string");
    fgets(str1,29,stdin);
    str1[strlen(str1)-1]='\0';
    puts("Enter second string");
    fgets(str2,29,stdin);
    str2[strlen(str2)-1]='\0';
    printf("%d",strcmp(str1,str2));
    return 0;
}
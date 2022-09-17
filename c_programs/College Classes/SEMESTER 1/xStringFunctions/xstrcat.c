/*Implementation of the strcat function*/
/*Concatenating two string together*/

#include<stdio.h>

int xstrlen(char* ptr)
{
    int i=0;
    while(ptr[i]!='\0')
        i++;
    return i;
}

void xstrcat(char *ptr1,char *ptr2 )
{
    int i=0,j=0;
    //locating the first \0 in str1
    while(ptr1[i]!='\0')
        i++;
    
    //concatenation
    while(ptr2[j]!='\0')
    {
        ptr1[i]=ptr2[j];
        i++;j++;
    }
    ptr1[i]='\0';
}

int main(void)
{
    char str1[20],str2[20];
    puts("Enter first string: ");
    fgets(str1,19,stdin);
    //Eliminating newlinefeed
    str1[xstrlen(str1)-1]='\0';
    puts("Enter second string: ");
    fgets(str2,19,stdin);
    //Eliminating newlinefeed
    str2[xstrlen(str2)-1]='\0';
    xstrcat(str1,str2);
    puts("Concatenated String: ");
    puts(str1);
    puts("Target String: ");
    puts(str2);
    return 0;
}
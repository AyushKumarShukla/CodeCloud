/*strcmp implementation*/

#include<stdio.h>

#include<stdio.h>

int xstrlen(char* ptr)
{
    int i=0;
    while(ptr[i]!='\0')
        i++;
    return i;
}

int xstrcmp(char *ptr1,char *ptr2)
{
    int i=0;
    while(1)
    {
        if(ptr1[i]!=ptr2[i] || ptr1[i]=='\0' || ptr2[i]=='\0')
            return ptr1[i]-ptr2[i];
        i++;
    }
}


int main(void)
{
    char str1[20],str2[20];
    int result=0;
    puts("Enter first string: ");
    fgets(str1,19,stdin);
    str1[xstrlen(str1)-1]='\0';
    puts("Enter second string: ");
    fgets(str2,19,stdin);
    str2[xstrlen(str2)-1]='\0';
    result=xstrcmp(str1,str2);
    printf("%d",result);
    return 0;


}
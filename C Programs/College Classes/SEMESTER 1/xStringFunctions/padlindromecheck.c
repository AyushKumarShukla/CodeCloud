/*WAP in to check whether a given string is a palindrome or not*/

#include<stdio.h>

int xstrlen(char* ptr)
{
    int i=0;
    while(ptr[i]!='\0')
        i++;
    return i;
   
}

void xstrrev(char *ptr)
{
    int i=0,j=0;
    while(ptr[i]!='\0')
        i++;
    for(i=i-1,j=0;j<i;i--,j++)
    {
        //swapping in place
        ptr[j]=ptr[j]+ptr[i];
        ptr[i]=ptr[j]-ptr[i];
        ptr[j]=ptr[j]-ptr[i];
    }
    
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
    char str1[20],cpy[20];
    puts("Enter a string:");
    fgets(str1,19,stdin);
    str1[xstrlen(str1)-1]='\0';
    xstrcpy(cpy,str1);
    xstrrev(cpy);
    if(strcmp(str1,cpy)==0)
        printf("%s is a palindrome",str1);
    else
        printf("%s is not a palindrome",str1);
    return 0;

}
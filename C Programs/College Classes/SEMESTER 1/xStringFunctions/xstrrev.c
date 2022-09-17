/*Implementation of the xstrrev function*/

#include<stdio.h>
//Never make one function's working depend upon another function,it is not necessary that the program will always have that function on which your function depends

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


int main(void)
{
    char str[50];
    puts("Enter a string: ");
    fgets(str,49,stdin);
    //Always deal with the newlinefeed
    //In this case if /n is not dealt with , it will swap the \n at the very beginning
    str[xstrlen(str)-1]='\0';
    xstrrev(str);
    puts("After Reversing: ");
    puts(str);
    return 0;
}
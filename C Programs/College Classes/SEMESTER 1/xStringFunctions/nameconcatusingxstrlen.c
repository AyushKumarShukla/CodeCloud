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
    char fname[20],lname[20],fullname[50]="";
    puts("Enter first string: ");
    fgets(fname,19,stdin);
    //Eliminating newlinefeed
    fname[xstrlen(fname)-1]='\0';
    puts("Enter second string: ");
    fgets(lname,19,stdin);
    //Eliminating newlinefeed
    lname[xstrlen(lname)-1]='\0';
    //make sure not to change fname or lname, make changes only in fullname
    xstrcat(fullname,fname);
    xstrcat(fullname," ");
    xstrcat(fullname,lname);
    puts("NAME: ");
    puts(fullname);
    return 0;
}
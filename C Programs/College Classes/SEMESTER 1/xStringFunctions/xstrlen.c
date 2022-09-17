/*Implementation of the strlen function*/

#include<stdio.h>

int xstrlen(char* ptr)
{
    int i=0;
    while(ptr[i]!='\0')
        i++;
    return i;
    //NOTE:when i becomes 6 , the while loop breaks,but i stands at the location of null character
    //i starts from 0 and ends at 6 , covering a total of 7 elements
    //But when we see the output , we conventionally think that counting has begun from 1
    //This coincidently gives us the desired result ie the \0 gets excluded even in presence of a discrepancy 
}

int main(void)
{
    char str[50];
    int len,i=0;
    puts("Enter a string"); // puts function adds a newline at the end
    fgets(str,49,stdin);
    //eliminating the newlinefeed from string using xstrlen function
    str[xstrlen(str)-1]='\0';
    printf("Length Of String: %d",xstrlen(str));
    return 0;
}

//We must not make humans count like pointers and pointers count like humans , we must treat both entities the way they like to work

/*Nesting Of Structures*/

#include<stdio.h>
#include<string.h>

int main(void)
{
    typedef struct address
    {
        int phone;int pin;
    }address;

    typedef struct student
    {
        char name[20];address a1;
    }student;

    student s1={"AYUSH",214,245};

    printf("%d",s1.a1.pin);


}
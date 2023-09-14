/*Passing structures in a variable*/
#include<stdio.h>

struct student
    {
        char name[20];int age;int sem;
    };

// Mixed Call
void disp1(char*name,int age,int sem)
{   
    printf("%s %d %d",name,age,sem);
}

void disp2(struct student s1)
{
    printf("\n%s %d %d",s1.name,s1.age,s1.sem);
}
//intriguing
void disp3(struct student *ptr)
{
    printf("\n%s %d %d",ptr->name,ptr->age,ptr->sem);
}

int main(void)
{
    
    struct student s1={"Ayush",18,2};
    disp1(s1.name,s1.age,s1.sem);
    disp2(s1);
    disp3(&s1);
    return 0;

}


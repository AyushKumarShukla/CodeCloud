/*Trying To implement linked lists*/

#include<stdio.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

int main(void)
{
    node n1;
    int x=10;
    n1.data=10;
    n1.next=&x;
    printf("%d",*n1.next);
}
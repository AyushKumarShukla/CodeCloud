#include<stdio.h>
#include<stdlib.h>

void showfibo(int prev,int current,int terms)
{
    unsigned int new;
    if(terms>=1)
    {
        new=prev+current;
        printf("%u\n",new);
        showfibo(current,new,terms-1);
    }
}
int main(void)
{
    int terms,prev,curr;
    prev=curr=1;
    printf("To print elements of the fibonacci sequence: ");
    printf("\nEnter the number of terms needed: ");
    scanf("%d",&terms);
    printf("%d %d ",prev,curr);
    showfibo(prev,curr,terms);
    return 0;
}

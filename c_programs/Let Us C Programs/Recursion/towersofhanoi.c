/*Solution of towers of Hanoi*/

#include<stdio.h>
#include<stdlib.h>
int i=1;
void move(int n,char org,char via,char des)
{
    if(n>0)
    {
        move(n-1,org,des,via);
        printf("\n\n%d. %c->%c",i++,org,des);
        move(n-1,via,org,des);
    }
}

int main(void)
{
    char org='A',via='B',des='C';
    int n;
    printf("Enter the number of rings: ");
    scanf("%d",&n);
    move(n,org,via,des);
}
#include<stdio.h>

int main(void)
{
    int i,j,num;
    printf("Enter the number of rows needed: ");
    scanf("%d",&num);

    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            if(j>=num-i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
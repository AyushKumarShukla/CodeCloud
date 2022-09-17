
#include<stdio.h>

int main(void)
{
    int i,j,num;
    printf("Enter the number of rows needed: ");
    scanf("%d",&num);


    for(i=1;i<=num;i++) // responsible for number of rows
    {
        for(j=1;j<=i;j++)
        {
            if((j==1&&i%2!=0)||(j%2==0&&i%2==0)||(j%2!=0&&i%2!=0))
            printf("%d",1);
            else
                printf("%d",0);
        }
        printf("\n");
    }
    return 0;
}
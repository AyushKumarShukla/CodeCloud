#include<stdio.h>

int main(void)
{
    int i,num,*ptr,sum=0;
    while(1)
    {
        printf("Enter the number of elements you need to add: ");
        scanf("%d",&num);
        if(num>50)
            printf("Invalid Input-Try Again\n");
        else
            break;
    }
    int arr[num];
    ptr=arr;
    printf("Enter the numbers to be added: ");
    for(i=0;i<num;i++)
        scanf("%d",ptr++);
    ptr=arr;
    for(i=0;i<num;i++)
        printf("%d",*(ptr++));
    ptr=arr;
    for(i=0;i<num;i++)
        sum = sum + *(ptr++);
    printf("The sum of the elements: %d",sum);
    return 0;
}
//declaration can be done anywhere
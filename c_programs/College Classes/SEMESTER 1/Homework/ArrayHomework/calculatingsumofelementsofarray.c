/*WAP in C to take n elements into an array , print and
calculate their sum*/

#include<stdio.h>

void input(int* x,int n)
{
    int i;
    printf("Enter elements in the array: ");
    for(i=0;i<n;i++)
        scanf("%d",&x[i]);
}

void disp(int *y,int j)
{
    int i;
    printf("The elements you entered are: ");
    for(i=0;i<j;i++)
        printf("%d ",y[i]);
}

int add(int* z,int k)
{
    int i,sum=0;
    for(i=0;i<k;i++)
        sum = sum + z[i];
    return sum;
}


int main(void)
{
    int arr[50],*ptr,num,i,sum=0;
    ptr=arr;
    //Taking number of elements as input
    while(1)
    {
        printf("Enter the number of elements to be added(<50): ");
        scanf("%d",&num);
        if(num>50)
            printf("Wrong Input Please Try Again");
        else
            break;
    }
    input(ptr,num);
    disp(ptr,num);
    sum = add(ptr,num);
    printf("\nThe sum of the elements is %d",sum);
    return 0;
}

/*
OUTPUT
*/
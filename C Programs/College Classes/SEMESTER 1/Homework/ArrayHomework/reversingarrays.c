/*WAP to reverse an array*/

#include<stdio.h>

void input(int* ptr, int num)
{
    int i;
    printf("Enter the values of array: ");
    for(i=0;i<num;i++)
        scanf("%d",&ptr[i]);
}

void rev(int* ptr1,int* ptr2, int num)
{
    int i,j;
    // Reversing the contents into the arrb
    for(i=num-1,j=0;i>=0;i--,j++)
        ptr2[j]=ptr1[i];//right value gets assigned to the left value
    // Copying the reversed array into arr
    for(i=0;i<num;i++)
        ptr1[i]=ptr2[i];
}


int main(void)
{
    int arr[50],arrb[50],*ptr1,*ptr2,num,i;
    ptr1=arr;
    ptr2=arrb;
    while(1)
    {
        printf("Enter the number of elements in array: ");
        scanf("%d",&num);
        if(num>50)
            printf("Wrong input-please try again");
        else
            break;
    }
    input(ptr1,num);
    rev(ptr1,ptr2,num);
    printf("The elements of the reversed array are: ");
    for(i=0;i<num;i++)
        printf("%d ",ptr1[i]);
    return 0;
}
/*
OUTPUT:
Enter the number of elements in array: 5
Enter the values of array: 1 2 3 4 5
The elements of the reversed array are: 5 4 3 2 1
--------------------------------
Process exited after 4.283 seconds with return value 0
Press any key to continue . . .

*/

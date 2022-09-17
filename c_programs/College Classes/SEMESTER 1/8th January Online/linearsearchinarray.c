//Linear Searching

#include<stdio.h>
int main(void)
{
    int arr[50],num,i,item,flag=0;
    while(1)
    {
        printf("Enter the total elements: ");
        scanf("%d",&num);
        if(num>50)
            printf("Invalid Input - Try Again: \n");
        else
            break;
    }
    //Taking Input In The Array
    printf("Enter %d elements",num);
    for(i=0;i<num;i++)
        scanf("%d",&arr[i]);
    //Printing The Elements Of The Array
    for(i=0;i<num;i++)
        printf("%d",arr[i]);
    printf("\nEnter the item that you want to search");
    scanf("%d",&item);
    //SEARCHING BEGINS
    for(i=0;i<num;i++)
    {
        if(arr[i]==item)
        {  
             printf("\nItem Found At Index %d",i);
            flag = 1;
        }
    }
    if(flag==0)
        printf("Item Not Found");
    return 0;
}
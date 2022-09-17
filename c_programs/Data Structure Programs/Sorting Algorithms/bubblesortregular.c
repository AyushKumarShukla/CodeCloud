/*Implementation Of Regular Bubble Sort*/

#include<stdio.h>
#include<conio.h>
void swap(int *a ,int *b)
{
    *a =*a+*b;
    *b =*a-*b;
    *a =*a-*b;
}

void bubblesort(int*arr,int len)
{
    int i,j;

    for(i=0;i<len-1;i++)
    {
        for(j=0;j<len-1;j++)
        {
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
        }
    }
}

int main(void)
{
    int arr[50],num,i;
    printf("To Sort A List Of Numbers:");
    printf("\nEnter The Number Of Elements Needed: ");
    scanf("%d",&num);
    //Input Validation
    if(num==0)
    {
        printf("Number Of Elements Cannot Be Zero");
    }
    printf("\nEnter The %d Elements",num);
    for(i=0;i<num;i++)
        scanf("%d",&arr[i]);
    printf("ENTERED ARRAY: ");
    for(i=0;i<num;i++)
        printf("%d ",arr[i]);
    bubblesort(arr,num);
    printf("\nSORTED ARRAY: ");
    for(i=0;i<num;i++)
        printf("%d ",arr[i]);
}
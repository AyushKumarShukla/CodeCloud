/*Implementation Of Regular Bubble Sort*/

#include<stdio.h>
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
        for(j=0;j<len-1-i;j++)
        {
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
        }
    }
}

void getarr(int*arr,int num)
{
    int i;
    for(i=0;i<num;i++)
            scanf("%d",&arr[i]);
}

void disparr(int*arr,int num)
{
    int i;
    for(i=0;i<num;i++)
        printf("%d ",arr[i]);
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
    getarr(arr,num);
    printf("ENTERED ARRAY: ");
    disparr(arr,num);
    bubblesort(arr,num);
    printf("\nSORTED ARRAY: ");
    disparr(arr,num);
}
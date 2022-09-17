/*Write a program in C to print the elements of Pascal triangle (take number of lines from user):*/

#include<stdio.h>
#include<math.h>

int fact(int num)
{
    int product=1,i;
    for(i=num;i>=1;i--)
    {
        product = product*i;
    }
    return product;
}

int main(void)
{
    int num,i,row=0,ele=0,item;
    printf("Enter the number of elements of the Pascal's Triangle you need: ");
    scanf("%d",&num);
    printf(" 1 ");//initial value
    for(i=1;i<=num-4;i++)
    {
        if(ele==row)
        {
            ele=0;
            row++;
            printf("\n");
            printf(" 1 ");
        }
        ele++;
        item = fact(row)/(fact(ele)*fact(row-ele));
        printf("%d ",item);
    }
    return 0;

}
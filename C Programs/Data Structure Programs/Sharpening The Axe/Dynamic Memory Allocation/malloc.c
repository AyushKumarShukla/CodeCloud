/*Implementation Of Malloc*/

#include<stdio.h>
#include<stdlib.h>


int main(void)

{
    int num,i;
    int* arrptr;
    printf("Enter The Elements Needed In Your Array: ");
    scanf("%d",&num);
    arrptr=(int*)malloc(num*sizeof(int));
    printf("Enter The Array Elements");
    for(i=0;i<num;i++)
        scanf("%d",&arrptr[i]);
    printf("The Array Elements Are: ");
    for(i=0;i<num;i++)
        printf("%d ",arrptr[i]);
        
    
}
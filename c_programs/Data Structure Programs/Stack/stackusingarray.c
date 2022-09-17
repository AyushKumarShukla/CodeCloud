#include<stdio.h>
#include<stdlib.h>

void display(int *arr, int top)
{
    int i;
    if(top==-1)
    {
        printf("Stack Is Empty\n");
        return;
    }
    printf("STACK: ");
    for(i=0;i<=top;i++)
        printf("%d ",arr[i]);
}

void push(int *arr,int* top,int ele)
{
    (*top)++; // ++ has a higher precedence but we need to access *top first,hence the parenthesis
    arr[*top]=ele;
    printf("PUSHED:%d\n",ele);
    display(arr,*top);
}

void pop(int* arr,int *top)
{
    printf("POPPED: %d\n",arr[*top]);
    (*top)--;
    display(arr,*top);
}

int main(void)
{
    int max,*arr,top,ch,ele,i;
    printf("Enter the size of the stack needed: ");
    scanf("%d",&max);
    arr=calloc(max,sizeof(int));
    top=-1;
    while(1)
    {
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                if(top==max-1)
                {
                    printf("Stack Overflow!");
                    return 0;
                }
                else
                {
                    printf("Enter The Element To Be Pushed: ");
                    scanf("%d",&ele);
                    push(arr,&top,ele);
                }
                break;
            case 2:
                if(top==-1)
                {
                    printf("Stack Underflow");
                    return 0;
                }
                else
                    pop(arr,&top);
                break;
            case 3:
                display(arr,top);
                break;
            case 4:
            	exit(0);
            default:
                printf("INVALID CHOICE\nPlease Try Again\n");
        }
    }
}

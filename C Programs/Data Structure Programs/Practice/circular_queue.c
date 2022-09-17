#include<stdio.h>
#include<stdlib.h>

void enqueue(int *arr,int item,int *front,int *rear,int max)
{
    *rear=(*rear+1)%max;
    arr[*rear]=item;
    if(*front==-1)
        *front=(*front+1)%max;
}

int dequeue(int *arr,int *front, int *rear,int max)
{
    int item;
    item=arr[*front];
    if(*front==*rear)
        *front=*rear=-1;
    else
        *front=(*front+1)%max;
    return item;
}

void display(int *arr,int *front,int *rear,int max)
{
    int i;
    if(*front==-1&&*rear==-1)
    {
        printf("Queue Empty");
        return;
    }
    for(i=*front;i!=*rear;i=((i+1)%max))
        printf("%d ",arr[i]);
    printf("%d ",arr[*rear]);
}
int main(void)
{
    int num,*arr,ch,front,rear,item;
    printf("Enter the size of the queue required: ");
    scanf("%d",&num);
    arr=(int*)malloc(num*sizeof(int));
    front=rear=-1;
    printf("To perfrom the following operations on a queue: ");
    while(1)
    {
        printf("\nMENU:");
        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.EXIT");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                if((rear+1)%num==front)
                {
                    printf("Queue Full");
                    exit(1);
                }
                else
                {
                    printf("Enter the element to be inserted: ");
                    scanf("%d",&item);
                    enqueue(arr,item,&front,&rear,num);
                    printf("QUEUE: \n");
                    display(arr,&front,&rear,num);
                }
                break;
            case 2:
                if(rear==-1)
                    printf("Queue Empty");
                else
                {
                    item=dequeue(arr,&front,&rear,num);
                    printf("DEQUEUED: %d",item);
                    printf("\nQUEUE: ");
                    display(arr,&front,&rear,num);
                }


        }
    }
}
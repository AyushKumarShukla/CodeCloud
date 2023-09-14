#include<stdio.h>
#include<stdlib.h>

void enqueue(int*arr,int *front,int*rear,int item,int max)
{
	if(*front==-1&&*rear==-1)
	{
		*front=*rear=0;
		arr[*rear]=item;
		return;
	}
	else
	{
		*rear=(*rear+1)%max;
	    arr[*rear]=item;
	}

}

int dequeue(int*arr,int*front,int*rear,int max)
{
	int item;
	item=arr[*front];
	if(*front==*rear)
	{
		*front=*rear=-1;
		return item;
	}
	else
		*front=(*front+1)%max;
	return item;
}

void dispq(int*arr,int*front,int*rear,int max)
{
	int i;
	i=*front;
	if(*front==-1&&*rear==-1)
	{
		printf("Queue is empty");
		return;
	}
	else
	{	
		printf("QUEUE:");
		while(i!=*rear)
		{
			printf("%d ",arr[i]);
			i=(i+1)%max;
		}
		printf("%d ",arr[*rear]);
	}
}


int main(void)
{
	int*arr,max,front,rear,ch,item;
	printf("Enter the size of the queue :");
	scanf("%d",&max);
	arr=(int*)calloc(max,sizeof(int));
	front=rear=-1;
	while(1)
	{
		printf("\nMENU\n");
		printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				if((rear+1)%max==front)
				{
					printf("QUEUE IS FULL");
					break;
				}
				else
				{
					printf("Enter the element to be inserted: ");
					scanf("%d",&item);
					enqueue(arr,&front,&rear,item,max);
					printf("INSERTED:%d\n",item);
				}
				dispq(arr,&front,&rear,max);
				break;
			case 2:
				if(front==-1&&rear==-1)
				{
					printf("Queue is already empty");
					break;
				}
				else{
					item=dequeue(arr,&front,&rear,max);
					printf("DELETED:%d\n",item);
				}
				dispq(arr,&front,&rear,max);
				break;
			case 3:
				dispq(arr,&front,&rear,max);
				break;
			case 4:
				exit(0);
			default:
				printf("Wrong Choice....Please Try Again");
		}
	}
	return 0;
}

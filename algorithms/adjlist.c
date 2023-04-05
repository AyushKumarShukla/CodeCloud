#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


typedef struct node
{
	int data;
	struct node *next;
}node;

node* createnode(int item)
{
	node *temp=(node*)malloc(sizeof(node));
	temp->next=NULL;
	temp->data=item;
	return temp;
}

node* insert_at_end(node* start, int item)
{
	node *temp, *ptr;
	temp=createnode(item);
	if(start==NULL)
		start=temp;
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=temp;
	}
	return start;
}

void displist(node* start)
{
	node* temp;
	temp=start;
	printf("\n");
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main(void)
{
	int item,num,i;
	node* start=NULL;
	printf("ENTER THE NUMBER OF ITEMS : ");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		printf("To insert at end, enter the item to be inserted: ");
		scanf("%d",&item);
		fflush(stdin);
		start=insert_at_end(start,item);
	}
	displist(start);
	return 0;
}


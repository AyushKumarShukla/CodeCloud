#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	struct node* prev;
	int data;
	struct node* next;
}node;

node* createnode(int item)
{
	node* ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=item;
	ptr->next=NULL;
	ptr->prev=NULL;
	return ptr;
}

node* end;

void displist(node *start)
{
	node *temp;
	temp=start;
	if(start==NULL)
	{
		printf("LIST EMPTY");
		return;
	}
	printf("LIST: ");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}


node* endinsert(node *start,int item)
{
	node *ptr,*temp;
	ptr=createnode(item);
	if(start==NULL)
	{
		start=ptr;
		end=ptr;
		return start;
	}
	else
	{
		end->next=ptr;
		ptr->prev=end;
		end=ptr;
		return start;
	}
}

node* frontinsert(node *start,int item)
{
	node *ptr;
	ptr=createnode(item);
	if(start==NULL)
	{
		start=ptr;
		end=ptr;
		return start;
	}
	else
	{
		ptr->next=start;
		start=ptr;//caution
		return start;
	}
}

int getmax(node* start)
{
	int count=0;
	node* temp=start;
	while(temp!=NULL)
	{
		temp=temp->next;
		count++;
	}
	return count;
}

node* insertatany(node* start,int item,int pos)
{
	node* ptr,*temp,*temp2;
	int count=1,max=getmax(start);
	if(pos==1)
		start=frontinsert(start,item);
	else if(pos==max)
		start=endinsert(start,item);
	else
	{
		ptr = createnode(item);
		temp = start;
		while(count!=pos-1)
		{
			count++;
			temp=temp->next;
		}
		temp2=temp->next;
		ptr->next=temp2;
		ptr->prev=temp;
		temp->next=ptr;
		temp2->prev=ptr;
	}
		return start;
	
}


node* frontdelete(node *start)
{
	node *ptr;
	ptr=start;
	if(start->next==NULL)
		start=NULL;
	else
	{
		start=start->next;
		start->prev=NULL;
	}
	free(ptr);
	return start;
}

void enddelete(node *start)
{
	node *temp,*temp2;
	temp=start;
	while((temp->next!=end))
		temp=temp->next;
	temp2=end;
	end=temp;
	end->next=NULL;
	free(temp2);
}

node* deletefromany(node* start,int pos)
{
	node* temp,*temp2,*temp3;
	int max=getmax(start);
	int count=0;
	if(pos==max)
		enddelete(start);
	else if(pos==1)
	{
		start=frontdelete(start);
		return start;
	}
	else
	{
		temp=start;
		while(count!=pos-2)
		{	count++;
			temp=temp->next;
		}

		temp2=temp->next;
		temp3=temp2->next;
		temp->next=temp3;
		temp3->prev=temp;
		free(temp2);
	}
	return start;
}

void disprev(node* start)
{
	node* ptr;
	ptr=end;
	if(start==NULL)
	{
		printf("LIST EMPTY");
		return;
	}
	printf("REVERSE LIST: ");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->prev;
	}
}

int main(void)
{
	node *start=NULL;
	int ch,item,pos,max;
	printf("To create a doubly linked list and perform the following operations:");
	while(1)
	{
		printf("\nMENU:");
		printf("\n1.INSERT AT END\n2.INSERT AT FRONT\n3.INSERT AT ANY POSITION\n4.DELETE FROM FRONT\n5.DELETE FROM END\n6.DELETE FROM ANY POSITION\n7.DISPLAY LIST\n8.DISPLAY LIST IN REVERSE\n9.EXIT");
		printf("\nEnter Your Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter the element to be inserted: ");
			scanf("%d",&item);
			start=endinsert(start,item);
			displist(start);
			break;

			case 2:
			printf("Enter the element to be inserted:");
			scanf("%d",&item);
			start=frontinsert(start,item);
			displist(start);
			break;

			case 3:
			if(start==NULL)
				start=endinsert(start,item);
			
			else
			{
				printf("Enter the insertion position: ");
				scanf("%d",&pos);
				max=getmax(start);
				//Checking validity of given position
				if(pos<1||pos>max+1)
					printf("\nInvalid Position\n");
				else
				{
					printf("Enter the element to be inserted:");
					scanf("%d",&item);
					start=insertatany(start,item,pos);
				}
			}
			displist(start);
			break;
			
			case 4:
			if(start==NULL)
				printf("LIST EMPTY");
			else
			{
				start=frontdelete(start);
				displist(start);
			}
			break;

			case 5:
			if(start==NULL)
				printf("LIST EMPTY");
			else
			{
				if(start->next==NULL)
					start=frontdelete(start);
				else
					enddelete(start);
				displist(start);
			}
			break;
			case 6:
			if(start==NULL)
				printf("LIST EMPTY");
			else
			{
				printf("Enter the deletion position: ");
				scanf("%d",&pos);
				max=getmax(start);
				if(pos<1 || pos>max)
					printf("Invalid position");
				else
				{
					start=deletefromany(start,pos);
					displist(start);
				}
			}
			break;

			case 7:
				displist(start);
			break;
			case 8:
				disprev(start);
			break;
			case 9:
				exit(0);
			break;
		}
	}
}

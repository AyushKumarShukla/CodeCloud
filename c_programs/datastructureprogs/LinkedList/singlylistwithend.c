#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int data;
	struct node* link;
}node;

node* createnode(int item)
{
	node* ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->link=NULL;
	ptr->data=item;
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
		temp=temp->link;
	}
}


node* endinsert(node *start,int item)
{
	node *ptr,*temp;
	ptr=createnode(item);
	if(ptr==NULL)
	{
		printf("Insufficient memory");
		exit(1);
	}
	if(start==NULL)
	{
		start=ptr;
		end=ptr;
	}
	else
	{
		end->link=ptr;
		end=ptr;
	}
	return start;
}

node* frontinsert(node *start,int item)
{
	node *ptr;
	ptr=createnode(item);
	if(ptr==NULL)
	{
		printf("Insufficient memory");
		exit(1);
	}
	if(start==NULL)
	{
		start=ptr;
		end=ptr;
	}
	else
	{
		ptr->link=start;
		start=ptr;
	}
	return start;
}

int getmax(node* start)
{
	int count=1;
	node* temp=start;
	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
	}
	return count;
}

node* insertatany(node* start,int item,int pos)
{
	node* ptr,*temp;
	int count=1,max=getmax(start);
	if(pos==1)
		start=frontinsert(start,item);
	else if(pos==max)
		start=endinsert(start,item);
	else
	{
		ptr = createnode(item);
		if(ptr==NULL)
		{	
			printf("Insufficient memory");
			exit(1);
		}
		temp = start;

		while(count!=pos-1)
		{
			count++;
			temp=temp->link;
		}
		ptr->link=temp->link;
		temp->link=ptr;
	}
	return start;
	
}



node* frontdelete(node *start)
{
	node *ptr;
	ptr=start;
	start=start->link;
	free(ptr);
	return start;
}

void enddelete(node *start)
{
	node *temp,*temp2;
	temp=start;
	while((temp->link!=end))
		temp=temp->link;
	temp2=end;
	end=temp;
	end->link=NULL;
	free(temp2);
}

node* deletefromany(node* start,int pos)
{
	node* temp,*temp2;
	int max=getmax(start);
	int count=1;
	if(pos==max)
		enddelete(start);
	else if(pos==1)
	{
		start=frontdelete(start);
	}
	else
	{
		temp=start;
		while(count!=pos-1)
		{	count++;
			temp=temp->link;
		}
		temp2=temp->link;
		temp->link=temp2->link;
		free(temp2);
	}
	return start;
}

int main(void)
{
	node *start=NULL;
	int ch,item,pos,max;
	while(1)
	{
		printf("\nMENU:");
		printf("\n1.INSERT AT END\n2.INSERT AT FRONT\n3.INSERT AT ANY POSITION\n4.DELETE FROM FRONT\n5.DELETE FROM END\n6.DELETE FROM ANY POSITION\n7.DISPLAY LIST\n8.EXIT");
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
				if(start->link==NULL)
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
				exit(0);
			break;
		}
	}
}

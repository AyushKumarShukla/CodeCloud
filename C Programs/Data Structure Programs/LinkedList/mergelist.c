#include<stdlib.h>
#include<stdio.h>

typedef struct node
{
	int data;
	struct node *link;
}node;

node* createnode(int item)
{
	node* ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=item;
	ptr->link=NULL;
	return ptr;
}

void displist(node *start)
{
	node *temp;
	temp=start;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
}
node *end;
node* insertnode(node* start,int item)
{
	node *ptr,*temp=start;
	ptr=createnode(item);
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


node* getlist(node *start,int len)
{
	int i,item;
	printf("Enter %d elements: ",len);
	for(i=0;i<len;i++)
	{
		scanf("%d",&item);
		start=insertnode(start,item);
	}
	return start;
}

node* mergelist(node* start1,node* start2,node* start3)
{
	node *temp1=start1,*temp2=start2;
	int i,j,k;
	while(temp1!=NULL && temp2!=NULL)
		{
			if((temp1->data)<=(temp2->data))
			{
				start3=insertnode(start3,temp1->data);
				temp1=temp1->link;
			}
			else
			{
				start3=insertnode(start3,temp2->data);
				temp2=temp2->link;
			}
		}
	if(temp1==NULL) //if list1 ends while list2 still remains
	{
		while(temp2!=NULL) // copy all the data of list2 to merged list
		{
			start3=insertnode(start3,temp2->data);
			temp2=temp2->link;
		}
	}
	else // if list2 ends while list1 still remains
	{
		while(temp1!=NULL) //copy all data of list1 to merged list
		{
			start3=insertnode(start3,temp1->data);
			temp1=temp1->link;
		}
	}
	return start3;
}

int main(void)
{
	node *start1=NULL,*start2=NULL,*start3=NULL;
	int len1,len2,len3=len1+len2;
	printf("To merge two sorted lists into a single list: \n");
	printf("Enter the length of the first list: ");
	scanf("%d",&len1);
	start1=getlist(start1,len1);
	printf("\nEntered List: ");
	displist(start1);
	printf("\nEnter the length of the second list: ");
	scanf("%d",&len2);
	start2=getlist(start2,len2);
	printf("\nEntered List: ");
	displist(start2);
	start3=mergelist(start1,start2,start3);
	printf("\nMerged List: ");
	displist(start3);
	return 0;
}

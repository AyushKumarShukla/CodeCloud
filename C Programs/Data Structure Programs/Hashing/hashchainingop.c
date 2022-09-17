#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    int index;
    struct node* link;
}node;

void getkey(int*arr,int num)
{
    int i;
    for(i=0;i<num;i++)
        scanf("%d",&arr[i]);
}
void showkey(int*arr,int num)
{
    int i;
    for(i=0;i<num;i++) 
        printf("%d ",arr[i]);
}
node* insertnode(node* start,int item)
{
    int cnt=1;
    node *ptr,*temp;
    ptr=(node*)malloc(sizeof(node));
    ptr->data=item;
    ptr->link=NULL;
    temp=start;
    if(temp==NULL)
    {
        start=ptr;
        ptr->index=0;
    }
    else
    {
        while(temp->link!=NULL)
        {
            temp=temp->link;
            cnt++;
            printf("CNT:%d",cnt);
        }
        temp->link=ptr;
        ptr->index=cnt;
    }

    return start;
}

void map(int*keys,node** hasharr,int numkey)
{
    int i,index;
    node *ptr;
    for(i=0;i<numkey;i++)
    {
        index=abs(keys[i])%10; //abs function returns the absolute value of argument
        if(hasharr[index]==NULL)
            hasharr[index]=insertnode(hasharr[index],keys[i]);
        else
           hasharr[index]=insertnode(hasharr[index],keys[i]);

    }
}
node** createhash(int* keys,int numkey)
{
    int i;
    node** hasharr;
    hasharr=(node**)malloc(10*sizeof(node*));
    for(i=0;i<10;i++)
        hasharr[i]=NULL;
    map(keys,hasharr,numkey);
    return hasharr;
}

void search(int item,node** hasharr)
{
    int ind;
    node* temp;
    ind=abs(item)%10;
    temp=hasharr[ind];
    do
    {
        if(temp->data==item)
        {
            printf("Item %d found at hash %d at index %d",item,ind,temp->index);
            return;
        }
        temp=temp->link;
    }while(temp!=NULL);
    printf("Item %d is not present in the hash",item);
    return;

}

int main(void)
{
    int numkey,*keys,item,ch=0;
    node** hasharr;
    printf("Enter the number of keys: ");
    scanf("%d",&numkey);
    keys=(int*)malloc(numkey*sizeof(int));
    printf("Enter %d values: ",numkey);
    getkey(keys,numkey);
    printf("Entered data: ");
    showkey(keys,numkey);
    hasharr=createhash(keys,numkey);
    while(ch==0)
    {
        printf("\nEnter the item to be searched: ");
        scanf("%d",&item);
        search(item,hasharr);
        printf("\nPress 0 to search another number\nPress 1 to exit: ");
        scanf("%d",&ch);
    }
    return 0;


}
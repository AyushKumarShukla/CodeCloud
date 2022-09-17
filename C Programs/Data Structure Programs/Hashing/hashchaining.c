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
node* insertnode(int item,int ind)
{
    node *ptr;
    ptr=(node*)malloc(sizeof(node));
    ptr->data=item;
    ptr->index=ind;
    ptr->link=NULL;
    return ptr;
}

void map(int*keys,node** hasharr,int numkey)
{
    int i,index,cnt=0;
    node *ptr;
    for(i=0;i<numkey;i++)
    {
        index=abs(keys[i])%10; //abs function returns the absolute value of argument
        if(hasharr[index]==NULL)
            hasharr[index]=insertnode(keys[i],0);
        else
        {
            ptr=hasharr[index];
            while(ptr->link!=NULL)
            {
                ptr=ptr->link;
                cnt++;
            }
            ptr->link=insertnode(keys[i],cnt+1);
        }

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
    int numkey,*keys,item;
    node** hasharr;
    printf("Enter the number of keys: ");
    scanf("%d",&numkey);
    keys=(int*)malloc(numkey*sizeof(int));
    printf("Enter %d values: ",numkey);
    getkey(keys,numkey);
    printf("Entered data: ");
    showkey(keys,numkey);
    hasharr=createhash(keys,numkey);
    printf("\nEnter the item to be searched: ");
    scanf("%d",&item);
    search(item,hasharr);
    return 0;


}
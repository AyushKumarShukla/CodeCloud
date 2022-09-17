#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node* lchild;
    int data;
    struct node* rchild;
}node;

node* search_BT(node* node,int item)
{
    if(node->data==item)
        return node;
    else
    {
        if(node->lchild!=NULL)
            search_BT(node->lchild,item);
        else if(node->rchild!=NULL)
            search_BT(node->rchild,item);
        else
            return NULL;
    }
    
}

node* createnode(int item)
{
    node* ptr;
    ptr=(node*)malloc(sizeof(node));
    ptr->data=item;
    ptr->lchild=ptr->rchild=NULL;
    return ptr;
}
void disp_inorder(node *root)
{
    if(root!=NULL)
    {
        disp_inorder(root->lchild);
        printf("%d ",root->data);
        disp_inorder(root->rchild);
    }
}
void insert_BT(node* root,int data,int item)
{
    int ch;
    node *temp,*ptr;
    temp=search_BT(root,item);
    if(temp!=NULL)
    {
        printf("Press 1 to insert at left child\nPress 2 to insert as right child");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                ptr=createnode(data);
                temp->lchild=ptr;
                break;
            case 2:
                ptr=createnode(data);
                temp->rchild=ptr;
                break;
            case 3:
                printf("\nInvalid Choice,Please Try Again");
        }
    }
    else
        printf("\nVALUE NOT FOUND IN TREE");
}

int main(void)
{
    node* root=NULL,*ptr;
    int data,num,item;
    printf("To Insert in a Binary Tree: ");
    while(1)
    {
        printf("\nEnter the data to be inserted: ");
        scanf("%d",&data);
        if(root==NULL)
        {
            ptr=createnode(data);
            root=ptr;
            continue;
        }
        printf("\nEnter the data after which the node is to be inserted: ");
        scanf("%d",&item);
        insert_BT(root,data,item);
        printf("\nTREE: ");
        disp_inorder(root);
    }
}
/*Basic operations on BST*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node* lchild;
    struct node* rchild;
}node;

node* createnode(int item)
{
    node *ptr=(node*)malloc(sizeof(node));
    ptr->lchild=ptr->rchild=NULL;
    ptr->data=item;
    return ptr;
}

node* insert(node* root,int item)
{
    node *ptr;
    if(root==NULL)
    {
        ptr=createnode(item);
        return ptr;
    }
    if(item<root->data)
        root->lchild=insert(root->lchild,item);
    else if(item>root->data)
        root->rchild=insert(root->rchild,item);
    return root;
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

void disp_preorder(node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        disp_preorder(root->lchild);
        disp_preorder(root->rchild);
    }
}

void disp_postorder(node *root)
{
    if(root!=NULL)
    {
        disp_postorder(root->lchild);
        disp_postorder(root->rchild);
        printf("%d ",root->data);
    }
}

node* search_BST(node *root,int item)
{
    if(root==NULL || root->data==item)
        return root;
    if(item>root->data)
        return search_BST(root->rchild,item);
    return search_BST(root->lchild,item);
}

int main(void)
{
    bool found=false;
    node *root=NULL,*root2=NULL;
    int ch,item;
    printf("To perform the following operations on a Binary Search Tree: ");
    while(1)
    {
        printf("\nMENU: ");
        printf("\n1.INSERT\n2.SEARCH\n3.DISPLAY\n4.EXIT");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d",&item);
            root=insert(root,item);
            printf("Elements of BST: \n");
            if(root!=NULL)
            { 
                printf("INORDER TRAVERSAL: ");
                disp_inorder(root);
                printf("\nPREORDER TRAVERSAL: ");
                disp_preorder(root);
                printf("\nPOSTORDER TRAVERSAL: ");
                disp_postorder(root);
            }
            else
                printf("Tree is empty");
            break;
            case 2:
            printf("Enter the key to be searched: ");
            scanf("%d",&item);
            if(root!=NULL)
                root2=search_BST(root,item);
            else
                printf("Tree is empty");
            if(root2==NULL)
                printf("Element %d not found in the tree",item);
            else
                printf("Element %d found in the tree",item);
            break;
            case 3:
            if(root!=NULL)
            { 
                printf("INORDER TRAVERSAL: ");
                disp_inorder(root);
                printf("\nPREORDER TRAVERSAL: ");
                disp_preorder(root);
                printf("\nPOSTORDER TRAVERSAL: ");
                disp_postorder(root);
            }
            else
                printf("Tree is empty");
            break;
            case 4:
            exit(0);
            
        }
    }
}

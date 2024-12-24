#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 6
#define NOPIVOT -1

typedef struct node {
    int key;
    int height;
    struct node *lchild;
    struct node *rchild;
    struct node *parent;
} Node;

Node* createNode(int key)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->key = key;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    newnode->parent = NULL;
    newnode->height = 0;
    return newnode;
}

int computeHeights(Node* root) {
    if (root == NULL)
        return -1;
    int hl = computeHeights(root->lchild);
    int hr = computeHeights(root->rchild);
    root->height = (hl > hr ? hl : hr) + 1;
    return root->height;
}

void left2left(Node **pivot) {
    Node *temp = (*pivot)->lchild;
    (*pivot)->lchild = temp->rchild;
    if (temp->rchild)
        temp->rchild->parent = *pivot;

    temp->rchild = *pivot;
    temp->parent = (*pivot)->parent;
    (*pivot)->parent = temp;

    *pivot = temp;

    // Update heights
    computeHeights((*pivot)->rchild);
    computeHeights(*pivot);
}

void right2right(Node **pivot) {
    Node *temp = (*pivot)->rchild;
    (*pivot)->rchild = temp->lchild;
    if (temp->lchild)
        temp->lchild->parent = *pivot;

    temp->lchild = *pivot;
    temp->parent = (*pivot)->parent;
    (*pivot)->parent = temp;

    *pivot = temp;

    // Update heights
    computeHeights((*pivot)->lchild);
    computeHeights(*pivot);
}

void left2right(Node **pivot) {
    Node *temp = (*pivot)->lchild;
    right2right(&temp);
    (*pivot)->lchild = temp;
    left2left(pivot);
}

void right2left(Node **pivot) {
    Node *temp = (*pivot)->rchild;
    left2left(&temp);
    (*pivot)->rchild = temp;
    right2right(pivot);
}

Node* insertHBT(Node* root, Node *newnode) {
    if (root == NULL) {
        return newnode;
    }

    if (newnode->key < root->key) {
        root->lchild = insertHBT(root->lchild, newnode);
        root->lchild->parent = root;
    } else if (newnode->key > root->key) {
        root->rchild = insertHBT(root->rchild, newnode);
        root->rchild->parent = root;
    }

    // Update height
    computeHeights(root);

    // Check balance factor and perform rotations
    int bf = (root->lchild ? root->lchild->height + 1 : 0) - (root->rchild ? root->rchild->height + 1 : 0);

    if (bf == 2) {
        int leftBf = (root->lchild->lchild ? root->lchild->lchild->height + 1 : 0) -
                     (root->lchild->rchild ? root->lchild->rchild->height + 1 : 0);
        if (leftBf >= 0)
            left2left(&root);
        else
            left2right(&root);
    } else if (bf == -2) {
        int rightBf = (root->rchild->lchild ? root->rchild->lchild->height + 1 : 0) -
                      (root->rchild->rchild ? root->rchild->rchild->height + 1 : 0);
        if (rightBf <= 0)
            right2right(&root);
        else
            right2left(&root);
    }

    return root;
}


int* getSequence(int *seq,int size)
{
    int i;
    seq = (int*)malloc(size * sizeof(int));
    for(i=0;i<size;i++)
        scanf("%d",&seq[i]);
    return seq;
}

void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->lchild);
    printf("Node: %d, Height: %d\n", root->key, root->height);
    inorderTraversal(root->rchild);
}

void preorderTraversal(Node* root)
{
    if(root == NULL)
        return;
    printf("Node: %d, Height: %d\n",root->key,root->height);
    preorderTraversal(root->lchild);
    preorderTraversal(root->rchild);
}

void postorderTraversal(Node* root)
{
    if(root == NULL)
        return;
    postorderTraversal(root->lchild);
    postorderTraversal(root->rchild);
    printf("Node: %d, Height: %d\n",root->key,root->height);
}


int main(void)
{
    int i;
    int size;
    int *seq;
    Node *newnode = NULL;
    Node *root = NULL;

    printf("Enter the number of elements: ");
    scanf("%d",&size);
    printf("Enter the sequence of %d elements: \n",size);
    seq = getSequence(seq,size);

    for (i = 0; i < size; i++)
    {
        newnode = createNode(seq[i]);
        root = insertHBT(root, newnode); // Update the root after insertion
    }
    printf("Inorder Traversal:\n");
    inorderTraversal(root);
    printf("\nPreorder Traversal:\n");
    preorderTraversal(root);
    printf("\nPostorder Traversal:\n");
    postorderTraversal(root);

    printf("\n");
    return 0;
}

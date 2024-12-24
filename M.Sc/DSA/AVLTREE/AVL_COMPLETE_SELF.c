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

// Function to find the inorder successor of a node
Node* inorderSuccessor(Node* node) {
    if (node == NULL)
        return NULL;

    // Case 1: If the node has a right child, the successor is the leftmost node of the right subtree
    if (node->rchild != NULL) {
        Node* temp = node->rchild;
        while (temp->lchild != NULL) {
            temp = temp->lchild;
        }
        return temp;
    }

    // Case 2: If the node does not have a right child, the successor is one of its ancestors
    if (node->lchild != NULL) {
        Node* temp = node->lchild;
        while (temp->rchild != NULL) {
            temp = temp->rchild;
        }
        return temp;
    }
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    // Step 1: Find the node to be deleted
    if (key < root->key) {
        root->lchild = deleteNode(root->lchild, key);
    } else if (key > root->key) {
        root->rchild = deleteNode(root->rchild, key);
    } else {
        // Step 2: Node to be deleted is found

        // Case 1: Node has no children (leaf node)
        if (root->lchild == NULL && root->rchild == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: Node has one child
        else if (root->lchild == NULL) {
            Node* temp = root->rchild;
            free(root);
            return temp;
        } else if (root->rchild == NULL) {
            Node* temp = root->lchild;
            free(root);
            return temp;
        }

        // Case 3: Node has two children
        else {
            // Find the in-order successor (smallest node in the right subtree)
            Node* successor = inorderSuccessor(root);
            root->key = successor->key;  // Replace the value of root with successor's key
            root->rchild = deleteNode(root->rchild, successor->key);  // Delete the successor
        }
    }

    // Step 3: Update height and balance the tree
    computeHeights(root);

    // Check balance factor and perform rotations if necessary
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

int* getSequence(int *seq, int size)
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

    printf("Preorder Traversal:\n");
    preorderTraversal(root);
    
    
    int deleteKey;
    while(true)
    {
        printf("\nEnter the value to delete: ");
        scanf("%d", &deleteKey);
        if(deleteKey==999)
            break;
        root = deleteNode(root, deleteKey); // Delete the node and balance the tree

        printf("Preorder Traversal after deletion:\n");
        preorderTraversal(root);
    }
    return 0;
}

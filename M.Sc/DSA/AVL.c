#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 5
#define NOPIVOT -1
/*
DEFS:
Height of a Node in a tree:
    => The number of nodes encountered in the branch starting from the given node and ending with the deepest
        leaf node reachable.
            For Example: 
                                                      4  <-- height = 4
                                                     / \
                              height = 2    --->    1   5 <-- height = 1
                                                     \   \
                              height = 1    --->      3   9 <-- height = 0
                                                     /
                              height = 0     --->    2
*/
typedef struct node{
	int key;
	int height;
	struct node *lchild;
	struct node *rchild;
    struct node *parent;
}Node;

Node* insertNode(int key)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	
	newnode->key = key;
	newnode->lchild = NULL;
	newnode->rchild = NULL;
	newnode->parent = NULL;
	return newnode;
}

int computeHeights(Node* root)
{
    Node *left = NULL;
    Node *right = NULL;
    int hl,hr;
    if(root == NULL)
        return -1;
    else
    {
        left = root->lchild;
        right = root->rchild;
        hl = computeHeights(left);
        hr = computeHeights(right);
        if(hl >= hr)
            root->height = hl + 1;
        else
            root->height = hr + 1;
        return root->height;
    }
}

//AVL ROTATIONS

//left to left rotation
void left2left(Node *pivot)
{
    Node *temp = NULL;
    
    // change pointers
    temp = pivot->lchild;

    pivot->lchild = temp->rchild;
    (temp->rchild)->parent = pivot;
    temp->rchild=pivot;
    pivot->parent = temp;

    //update heights
    pivot->height = computeHeights(pivot);
    temp->height = computeHeights(temp);

    //set temp as the new pivot;
    pivot = temp;
}

//right to right rotation
void right2right(Node *pivot)
{
    Node *temp = NULL;

    temp = pivot->rchild;

    pivot->rchild = temp->lchild;
    (temp->lchild)->parent = pivot;
    temp->lchild = pivot;
    pivot->parent=temp;

    //update heights
    pivot->height = computeHeights(pivot);
    temp->height = computeHeights(temp);

    //set temp as the new pivot;
    pivot = temp;
}

//left to right rotation
void left2right(Node *pivot)
{
    Node *temp = NULL;

    temp = pivot->lchild;
    right2right(temp);
    left2left(pivot);
}

//right to left rotation
void right2left(Node *pivot)
{
    Node *temp = NULL;

    temp = pivot->rchild;
    left2left(temp);
    right2right(pivot);
}

Node* findPivot(Node *newNode)
{
    return NULL;
}

Node* constructAVL(int* seq,int size)
{
	int i;
    int hl,hr,bf;
	Node *root = NULL;
	Node *curr = NULL;
    Node *pivot = NULL;
	for(i=0;i<size;i++)
	{
		// tree is empty
		if(root == NULL)
		{
			root = insertNode(seq[i]);
		}
		else
		{
			//tree has the root
			curr = root;
			while(true)
			{
				// argument is less than current node key
				if(seq[i]<(curr->key))
				{
					if(curr->lchild != NULL)
						curr = curr->lchild;
					else
					{
						curr->lchild = insertNode(seq[i]);
                        (curr->lchild)->parent = curr;
                       
                       //check for unbalance after insertion
                        pivot = findPivot(curr->lchild);
                        if(pivot != NULL)
                        {
                            hl = computeHeights();
                            hr = computeHeights();
                            bf = hl - hr;
                            if(bf == 2)
                                //left to left rotation
                            else
                                //left to right rotation
                        }
                        else
                            //balance not broken
						break;
					}
				}
				else // argument is greater than current node key
				{
					if(curr->rchild != NULL)
						curr = curr->rchild;
					else
					{
						curr->rchild = insertNode(seq[i]);
                        (curr->rchild)->parent = curr;
                       
                       //check for unbalance after insertion
                        pivot = findPivot(curr->rchild);
                        if(pivot != NULL)
                        {
                           
                            hl = computeHeights();
                            hr = computeHeights();
                            bf = hl - hr;
                            if(bf == -2)
                                //right to right rotation
                            else
                                //right to left rotation
                        }
                        else
						break;
					}
				}
			}
		}
	}
    //check if bf of any node in insertion branch becomes 2
        // if it does, perform appropriate AVL Rotations on the node with bf 2 nearest to the inserted node.
	return root;
}

void inorderTraversal(Node *root)
{
	if(root == NULL)
		return;
	else
	{
		inorderTraversal(root->lchild);
		printf("Node:%d, Height:%d\n",root->key,root->height);
		inorderTraversal(root->rchild);
	}
}

int main(void)
{
	int size = SIZE;
	int seq[SIZE] = {4,5,9,1,3};
	
	Node* root = constructAVL(seq,size);
    computeHeights(root);
	inorderTraversal(root);

    printf("\n");
    return 0;
}

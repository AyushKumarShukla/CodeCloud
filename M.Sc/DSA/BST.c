#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
	int key;
	int bf;
	struct node *lchild;
	struct node *rchild;
}Node;

Node* insertNode(int key)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	
	newnode->key = key;
	newnode->lchild = NULL;
	newnode->rchild = NULL;
	
	return newnode;
}

Node* constructAVL(int* seq,int size)
{
	int i;
	Node *root = NULL;
	Node *curr = NULL;
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
						break;
					}
				}
			}
		}
	}
	return root;
}

void inorderTraversal(Node *root)
{
	if(root == NULL)
		return;
	else
	{
		inorderTraversal(root->lchild);
		printf("%d ",root->key);
		inorderTraversal(root->rchild);
	}
}

int main(void)
{
	int size = 5;
	int seq[5] = {4,5,9,1,3};
	
	Node* root = constructAVL(seq,size);
	inorderTraversal(root);
}

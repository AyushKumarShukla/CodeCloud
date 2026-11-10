#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAXLEVEL 4
#define p 0.5

typedef struct Node{
	int key;
	int value;
	struct Node** forward;
}Node;

typedef struct{
	int level;
	Node* header;
}List;

Node null_node = {INT_MAX,INT_MAX,NULL};


int randomLevel(){
	int lvl=1;
	while((( (double)rand() / RAND_MAX)<p && lvl<MAXLEVEL))
		lvl++;
	return lvl;
}

Node* makeNode(int lvl,int searchKey,int newValue){	
	Node* newNode = malloc(sizeof(Node));
	newNode->key = searchKey;
	newNode->value = newValue;
	newNode->forward = (Node**)malloc(sizeof(Node*) * lvl);
	return newNode;
}

void insert(List* l, int searchKey, int newValue){
	Node* update[MAXLEVEL];
	for(int i=0;i<MAXLEVEL;i++) update[i] = NULL;
	Node* x = l->header;
	for(int i=l->level-1;i>=0;i--){
		while(x->forward[i]->key < searchKey){
			x = x->forward[i];
		}
		update[i] = x;
	}
	x = x->forward[0];
	if(x->key==searchKey)
		x->value = newValue;
	else{
		int lvl = randomLevel();
		
		if(lvl > l->level){
			for(int i=l->level;i<lvl;i++){
				update[i] = l->header;
			}
			l->level = lvl;
		}
		x = makeNode(lvl,searchKey,newValue);
		for(int i=0;i<lvl;i++){
			x->forward[i] = update[i]->forward[i];
			update[i]->forward[i] = x;
		}
	}
}

void printList(List* l){
    for(int i=l->level-1;i>=0;i--){
        printf("L%d: H",i);
        for(Node* x=l->header->forward[i];x!=&null_node;x=x->forward[i])
            printf(" -> %d",x->key);
        printf(" -> NIL\n");
    }
}

int main(void){
	Node** forward = malloc(sizeof(Node*) * MAXLEVEL);
	for(int i=0;i<MAXLEVEL;i++) forward[i] = &null_node;
	Node header = {-INT_MAX,-INT_MAX,forward};
	List l = {1,&header};
	insert(&l,5,10);
	insert(&l,6,15);
	insert(&l,3,-5);
	insert(&l,1,200);
	insert(&l,14,-25);
	insert(&l,7,19);
	insert(&l,2,8);
	insert(&l,4,40);
	printList(&l);
}

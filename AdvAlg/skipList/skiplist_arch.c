#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include<stdbool.h>
#include"avl_perf.h"

#define MAXLEVEL 8
#define p 0.5
#define MAX_ELEMENT 1e9
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

int main(int argc, char* argv[]){
	bool app_running=true;
	srand(time(0));
	struct timespec start,end;

	/*if(argc < 2){
		printf("Usage: ./skiplist <integer>\n");
		exit(1);
	}
	int num = atoi(argv[1]);
	*/

	Node** forward = malloc(sizeof(Node*) * MAXLEVEL);
	for(int i=0;i<MAXLEVEL;i++) forward[i] = &null_node;
	Node header = {-INT_MAX,-INT_MAX,forward};

	AVLPerfTree* avl = avl_perf_create();	

	List l = {1,&header};
	int ch;
	int num;
	while(app_running){
		printf("1. Insert N elements\n2. Time next insertion\n3. Time search\n4. Print\n5.Exit");
		printf("\nSelect an option: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("N: ");
				scanf("%d",&num);

				for(int i=0;i<num;i++){
					int value = rand()%(int)MAX_ELEMENT;
					insert(&l,i,value);
					avl_perf_insert(avl,i,value);
				}

				break;
			case 2:
				int key,value;
				double time_elapsed;
				printf("(Key,Value): ");
				scanf("%d%d",&key,&value);

				//skiplist check
				clock_gettime(CLOCK_MONOTONIC, &start);
				insert(&l,key,value);
				clock_gettime(CLOCK_MONOTONIC, &end);
				time_elapsed 
					= (end.tv_sec - start.tv_sec) + 
					  (end.tv_nsec - start.tv_nsec)/ 1000000000.0;

				printf("Time Taken by Skiplist: %.9f Seconds\n",time_elapsed);
				
				//AVL Tree check
				clock_gettime(CLOCK_MONOTONIC, &start);
				avl_perf_insert(avl,key,value);
				clock_gettime(CLOCK_MONOTONIC, &end);
				time_elapsed 
					= (end.tv_sec - start.tv_sec) + 
					  (end.tv_nsec - start.tv_nsec)/ 1000000000.0;
				printf("\nTime Taken by AVL Tree: %.9f Seconds\n",time_elapsed);
				break;
			case 3:
				break;
			case 4:
				printList(&l);
				break;
			case 5:
				app_running=false;
				break;
		}	
	}
	return 0;
}

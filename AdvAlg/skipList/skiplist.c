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

size_t skiplist_bytes = 0;

Node* makeNode(int lvl,int searchKey,int newValue){	
	Node* newNode = malloc(sizeof(Node));
	newNode->key = searchKey;
	newNode->value = newValue;
	newNode->forward = (Node**)malloc(sizeof(Node*) * lvl);
	skiplist_bytes += sizeof(newNode) + sizeof(Node*) * lvl;
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
		printf("1. Benchmark Insertion\\Search \n2. Print\n3.Exit");
		printf("\nSelect an option: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				FILE *fp = fopen("insertion_benchmark.txt","w");
				FILE *gnuplot = popen("gnuplot","w");
				fprintf(fp,"#size\ttime_skiplist\ttime_AVLTree\tmem_skiplist\tmem_AVLTree\n");
				if(fp == NULL){
					printf("File Error");
					exit(1);
				}
				if(gnuplot == NULL){
					printf("Cannot open GNUPlot");
					exit(2);
				}

				int begin,stop,step;
				int key,value;
				double time_elapsed;
				
				printf("(begin,end,step): ");
				scanf("%d%d%d",&begin,&stop,&step);
				
				int loop_start=0;

				while(begin<stop){
					for(int i=loop_start;i<begin;i++){
						int value = rand()%(int)MAX_ELEMENT;
						insert(&l,i,value);
						avl_perf_insert(avl,i,value);
					}

					key = begin;
					value = -150;

					clock_gettime(CLOCK_MONOTONIC, &start);
					insert(&l,key,value);
					clock_gettime(CLOCK_MONOTONIC, &end);
					time_elapsed 
						= (end.tv_sec - start.tv_sec) + 
						  (end.tv_nsec - start.tv_nsec)/ 1000000000.0;

					printf("Skiplist [N=%d]:\t%.9f Seconds\n",begin,time_elapsed);
					double skiplist_time = time_elapsed;
					//AVL Tree check
					clock_gettime(CLOCK_MONOTONIC, &start);
					avl_perf_insert(avl,key,value);
					clock_gettime(CLOCK_MONOTONIC, &end);
					time_elapsed 
						= (end.tv_sec - start.tv_sec) + 
						  (end.tv_nsec - start.tv_nsec)/ 1000000000.0;
					printf("AVLTree [N=%d]:\t%.9f Seconds\n\n",begin,time_elapsed);
					double avl_time = time_elapsed;
						
	fprintf(fp,"%d\t%.9f\t%.9f\t%zu\t%zu\n",begin,skiplist_time,avl_time,skiplist_bytes,avl_bytes);
					begin = begin+step;
					loop_start = begin;
				}
				fclose(fp);

	
	fprintf(gnuplot, "set grid\n");
	fprintf(gnuplot, "set xlabel 'size'\n");

	fprintf(gnuplot, "set terminal qt 0\n");
	fprintf(gnuplot, "set title 'Skiplist vs AVL Tree: Search/Insertion Time Comp.'\n");
	fprintf(gnuplot, "set ylabel 'time(s)'\n");
	fprintf(gnuplot, "plot 'insertion_benchmark.txt' using 1:2 with linespoints title 'skiplist',""'insertion_benchmark.txt' using 1:3 with linespoints title 'AVLTree'\n");
	fprintf(gnuplot, "pause mouse close\n");

	fprintf(gnuplot, "set terminal qt 1\n");
	fprintf(gnuplot, "set title 'Skiplist vs AVL Tree: Memory usage Comp.'\n");
	fprintf(gnuplot,"set ylabel 'allocated memory(bytes)'\n");

	fprintf(gnuplot, "plot 'insertion_benchmark.txt' using 1:4 with linespoints title 'skiplist',""'insertion_benchmark.txt' using 1:5 with linespoints title 'AVLTree'\n");
	fprintf(gnuplot, "pause mouse close\n");

				fflush(gnuplot);
				pclose(gnuplot);
				break;
			case 2:
				printList(&l);
				break;
			case 3:
				app_running=false;
				break;
		}	
	}
	return 0;
}

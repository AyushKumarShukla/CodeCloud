#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include<stdbool.h>
#include"avl_perf.h"

#define MAXLEVEL 32
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
            printf(" -> [%d | %d] ",x->key,x->value);
        printf(" -> NIL\n");
    }
}

int list_search_path_length;
int search(List* l, int search_key){
	list_search_path_length = 0;
	Node* x = l->header;
	for(int i=l->level-1;i>=0;i--){
		while(x->forward[i]->key < search_key){
			x = x->forward[i];
			list_search_path_length++;
		}
	}
	x = x->forward[0];
	list_search_path_length++;
	if(x->key == search_key)
		return x->value;
	return -1;
}

int main(void){
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
	while(app_running){
		printf("1. Benchmark Insertion\n2. Insert and Search \n3. Print\n4.Exit");
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
				FILE *pl = fopen("path_lengths.txt","w");
				FILE *gp = popen("gnuplot","w");

				fprintf(pl,"#N\t#skiplist\t#avltree\n");

				int N,skey,ret,iter_num;
				printf("Enter N,iter_num: ");
				scanf("%d%d",&N,&iter_num);
				int iter_cnt = 0;
				while(iter_cnt < iter_num){
				//reinitialize skiplist and avl tree
       				Node** forward = malloc(sizeof(Node*) * MAXLEVEL);
			         for(int i=0;i<MAXLEVEL;i++) forward[i] = &null_node;
				 Node header = {-INT_MAX,-INT_MAX,forward};

				 AVLPerfTree* avl = avl_perf_create();
				 List l = {1,&header};


				for(int i=0;i<N;i++){
					int rval = rand()%1000;
					insert(&l,i,rval);
					avl_perf_insert(avl,i,rval);
				}
				//printList(&l);
				//printf("search_key:");
				//scanf("%d",&skey);
				skey =  N-1;
				if( (ret = search(&l,skey)) > 0 )
					printf("\nlist found: path length: %d, value: %d\n",list_search_path_length,ret);
				else
					printf("list: NA");

				if( (ret = avl_perf_search(avl,skey)) > 0)
					printf("\navl found: path length: %d, value: %d\n",avl_search_path_length,ret);
				else
					printf("list: NA");
				fprintf(pl,"%d\t%d\t%d\n",N,list_search_path_length,avl_search_path_length);
				iter_cnt++;
			}
				fclose(pl);
				fprintf(gp,"stats 'path_lengths.txt' using 2:3\n");
				pclose(gp);
				break;
			case 3:
				printList(&l);
				break;
			case 4:
				app_running=false;
				break;
		}	
	}
	return 0;
}

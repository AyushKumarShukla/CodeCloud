#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define LABEL 4
#define CREDIT_SCORE 3
#define STUDENT 2
#define INCOME 1
#define AGE 0
#define BUY 1
#define NO_BUY 0
int **alloc_matrix(int rows, int cols){
	int i;
	int **m = malloc(rows * sizeof(int*));
	
	m[0] = malloc(rows*cols*sizeof(int));
	
	for(i=1;i<rows;i++)
		m[i] = m[0] + i * cols;
	return m;
}

int **read_matrix(const char *filename, int *rows, int *cols){
	
	FILE *fp = fopen(filename, "r");
	
	int **dataset;
	int i,j;
	
	if(!fp){
		fprintf(stderr,"cannot access file\n");
		exit(1);
	}

	if(fscanf(fp,"%d %d",rows,cols) != 2){
		fprintf(stderr,"invalid matrix header. \n");
		exit(2);
	}

	dataset = alloc_matrix(*rows, *cols);
	for(i=0;i<*rows;i++){
		for(j=0;j<*cols;j++){
			if(fscanf(fp,"%d", &dataset[i][j]) != 1){
					fprintf(stderr, "Invalid matrix content");
					exit(3);
			}
		}
	}
	fclose(fp);
	return dataset;
}

double P(int **dataset, int row_cnt, int c){
	int i;
	double sum=0.0;
	for(i=0;i<row_cnt;i++){
		if(dataset[i][LABEL] == c)
			sum += 1;
	}

	return(sum/(double)row_cnt);
}

int label_count(int **dataset, int row_cnt, int label_value){
	int i;
	int lcount = 0;
	for(i=0;i<row_cnt;i++){
		if(dataset[i][LABEL] == label_value)
			lcount++;
	}
	return lcount;
}

double CCP(int **dataset, int row_cnt, int attr, int attr_in_X, int label_value){
	int i;
	double sum=0.0;
	for(i=0;i<row_cnt;i++){
		if(dataset[i][attr] == attr_in_X && dataset[i][LABEL] == label_value)
			sum += 1;
	}
	return (sum/(double)label_count(dataset,row_cnt,label_value));
}

int main(void){
	int row_cnt, col_cnt;
	int i,j;
	int **dataset;
	int X[4] = {0,1,1,0};
	dataset = read_matrix("dataset.txt",&row_cnt, &col_cnt);
	printf("Computer Sale Dataset: \n");
	for(i=0;i<row_cnt;i++){
		for(j=0;j<col_cnt;j++)
			printf("%d ",dataset[i][j]);
		printf("\n");
	}
	/*CLASSIFICATION LOGIC*/
	int CLASS_COUNT = 2;
	double P_0 = P(dataset,row_cnt,0); 
	double P_1 = P(dataset,row_cnt,1); 
	printf("Probability of class label being 0 = %f\n", P_0);
	printf("Probability of class label being 1 = %f\n", P_1);

	printf("P(AGE=0(YOUTH) and BUYS_COMPUTER) = %f\n",CCP(dataset,row_cnt,AGE,X[AGE],BUY));
	printf("P(AGE=0(YOUTH) and NOT_BUYS_COMPUTER) = %f\n",CCP(dataset,row_cnt,AGE,X[AGE],NO_BUY));
	
	printf("P(INCOME=1(MEDIUM) and BUYS_COMPUTER) = %f\n",CCP(dataset,row_cnt,INCOME,X[INCOME],BUY));
	printf("P(INCOME=1(MEDIUM) and NOT_BUYS_COMPUTER) = %f\n",CCP(dataset,row_cnt,INCOME,X[INCOME],NO_BUY));
	
	printf("P(STUDENT=1(YES) and BUYS_COMPUTER) = %f\n",CCP(dataset,row_cnt,STUDENT,X[STUDENT],BUY));


	printf("P(CREDIT=0(FAIR) and BUYS_COMPUTER) = %f\n",CCP(dataset,row_cnt,CREDIT_SCORE,X[CREDIT_SCORE],BUY));
	printf("P(CREDIT=0(FAIR) and NOT_BUYS_COMPUTER) = %f\n",CCP(dataset,row_cnt,CREDIT_SCORE,X[CREDIT_SCORE],NO_BUY));
	/*CLASSIFICATION LOGIC*/
	double prod = 1.0;
	for(i=0;i<col_cnt;i++)
		prod *= CCP(dataset,row_cnt,i,X[i],BUY);
	printf("\nProbability X Buys a Computer is %f",prod * P_1);

	prod = 1.0;
	for(i=0;i<col_cnt;i++){
		prod *= CCP(dataset,row_cnt,i,X[i],NO_BUY);
		printf("\nprod: %f, CCP:%f\n", prod, CCP(dataset,row_cnt,i,X[i],NO_BUY));
	}
	
	printf("\nProbability X Does Not Buy a Computer is %f",prod * P_0);
	free(dataset[0]);
	free(dataset);
	return 0;
}


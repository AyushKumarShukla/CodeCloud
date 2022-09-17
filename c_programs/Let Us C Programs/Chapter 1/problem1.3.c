/* Program to find the aggregate and percent marks of a student for five subjects */

#include<stdio.h>

int main()
{
	float s1,s2,s3,s4,s5;
	float agg_marks,prcnt;
	printf("Enter The Marks Obtained In S1, S2, S3, S4 and S5 respectively: ");
	scanf("%f%f%f%f%f",&s1,&s2,&s3,&s4,&s5);
	
	agg_marks = (s1+s2+s3+s4+s5);
	prcnt = (float)(agg_marks / 500)*100;
	printf("Aggregate Marks: %f\n",agg_marks);
	printf("Percentage: %f",prcnt);
	return 0 ;
	
	
	
	
	
	
	
	
}

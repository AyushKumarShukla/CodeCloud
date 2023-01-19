/*Newton's Backward Interpolation Formula Calculation*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//tested 
void getarray(float(*arr)[20],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
		for(j=col;j<col+1;j++)
			scanf("%f",&arr[i][j]);

}
//tested
void disparray(float(*arr)[20],int row,int col)
{
	int i,j;
	printf("x\t\ty\t\t");
	for(i=0;i<(row-1);i++)
	{
		printf("d%-dy\t\t",i+1);
	}
	printf("\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(j<=(col-i)-1) //necessary condition to print the desired difference table
				printf("%-10.4f\t",arr[i][j]);
		}
		printf("\n");
	}
}
//tested
void createtable(float(*arr)[20],int row_count)
{
	int i,j,col=2,count=1;
	while(count<row_count)
	{
		for(i=0;i<row_count;i++)
		{
			arr[i][col]=arr[i+1][col-1]-arr[i][col-1];
		}
		col++;
		count++;
	}
}

float fact(float num)
{
	if(num<=1)
		return 1;
	else
		return num*fact(num-1);
}

void calc(float(*arr)[20],int row,float find,float phase)
{
	int i,j;
	float temp=0,factor=1,tphase=phase;
	for(i=0;i<row-1;i++)
	{
		for(j=-1;j<i;j++)
		{
			factor=factor*tphase;
			tphase++;
		}
		//debugging
		temp=temp+((factor/fact(i+1))*(arr[row-2-i][i+2])); //the order of operations matters, use parenthesis carefully
		//the factorials were at the wrong positions in the equations,that is they were with terms that the factorials were not associated with
		//reseting variable values is important for next iteration
		factor=1;
		tphase=phase;
	}
	temp=temp+arr[row-1][1];
	printf("\nValue of f(%.4f) : %.4f",find,temp);
}

int main(void)
{
	int terms,i,j;
	float mat[20][20],val,result,phase,height;;
	memset(mat,0,sizeof(mat));
	printf("To perform interpolation using Newtons' Backward Difference formula:\n");
	printf("Enter the number of given terms: ");
	scanf("%d",&terms);
	if(terms<1)
	{
		printf("Invalid Input\n");
		exit(1);
	}
	printf("Enter the values of x: ");
	getarray(mat,terms,0);

	printf("Entered Values of x: \n");
	disparray(mat,terms,terms+1);

	printf("\nEnter the values of y: ");
	getarray(mat,terms,1);

	printf("Entered Values of y: \n");
	disparray(mat,terms,terms+1);

	printf("Enter the value of x to find f(x): ");
	scanf("%f",&val);

	createtable(mat,terms);
	printf("Forward Difference Table: \n");
	disparray(mat,terms,terms+1);

	height=mat[1][0]-mat[0][0];
	phase=(val-mat[terms-1][0])/height;
	calc(mat,terms,val,phase);
	printf("\n");
	return 0;
}

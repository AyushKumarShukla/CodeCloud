#include<stdio.h>
#include<stdlib.h>
// function for input validation
void validate(int row,int col)
{
	if(row!=col)
	{
		printf("Triangular Matrix Must Be A Square Matrix!\nPlease Try Again\n");
		exit(1);
	}
	return;
}
// function to ask the user whether to continue with new input
void prompt(void)
{
	int ch;
	while(1)
	{
		printf("Press 1 to continue OR press 0 to exit: ");
		scanf("%d",&ch);
		if(ch==1)
			return;
		else if(ch==0)
			exit(0);
		printf("\nInvalid Input, Please Try Again\n");
	}
}

// function to take input in a matrix
void getmat(int(*arr)[20],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			scanf("%d",&arr[i][j]);
}

//function to display a matrix
void dispmat(int(*arr)[20],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			printf("%d\t",arr[i][j]);
		printf("\n");
	}
}

//function to check whether input matrix is a upper triangular matrix
void isuppertri(int(*arr)[20],int row,int col)
{
	int i,j;
	for(i=1;i<row;i++) //traversing the lower triangular part
		for(j=0;j<i;j++)
			if(arr[i][j]!=0) // if an element is not zero
				{
					printf("\nEntered Matrix Is Not A Upper Triangular Matrix\n");
					exit(1); // terminate the program
				}
	printf("\nEntered Matrix Is A Upper Triangular Matrix");
}

//function to check whether input matrix is a lower triangular matrix
void islowertri(int(*arr)[20],int row,int col)
{
	int i,j;
	for(i=1;i<row;i++) //traversing the upper triangualar part
		for(j=0;j<i;j++)
			if(arr[j][i]!=0) //if an element is not zero
				{
					printf("\nEntered Matrix Is Not A Lower Triangular Matrix\n");
					exit(1); //terminate the program
				}
	printf("\nEntered Matrix Is A Lower Triangular Matrix");
}

//function to feed upper triangular matrix in 1-D array
void makeupperlist(int*list,int(*arr)[20],int row,int col)
{
	int i,j,k=0;

	for(i=0;i<row;i++) //traversing the upper triangular part
		for(j=i;j<col;j++)
		{
			list[k]=arr[i][j]; //feeding the 1-D array
			k++;	
		}
}

//function to feed lower triangular matrix in 1-D array
void makelowerlist(int*list,int(*arr)[20],int row,int col)
{
	int i,j,k=0;

	for(i=0;i<row;i++) //traversing the lower triangular part
		for(j=0;j<(i+1);j++)
		{
			list[k]=arr[i][j]; //feeding the 1-D array
			k++;
		}
}

//function to display a 1-D array
void displist(int*arr,int size)
{
	int i;
	for(i=0;i<size;i++)
		printf("%d ",arr[i]);
}

//function to reconstruct matrix from 1-D array
void reconsuppmat(int* arr,int row)
{
	int i,j,k,l=0,limit;
	limit=row;
	for(i=0;i<row;i++)
	{
		for(j=limit;j<row;j++) //for non upper triangular positions
			printf("0\t"); //display 0
		for(k=0;k<limit;k++) // for upper triangular positions
		{
			printf("%d\t",arr[l]); //display contents of 1-D array
			l++;
		}
		limit--;
		printf("\n");
	}
}

//function to reconstruct matrix from 1-D array
void reconslowmat(int* arr,int row)
{
	int i,j,k,l=0,lim=row;
	for(i=0;i<row;i++)
	{
		for(j=(lim-1);j<row;j++) //for lower triangular positions
		{
			printf("%d\t",arr[l]); //display contents of 1-D array
			l++;
		}
		for(k=1;k<lim;k++) //for non lower triangular positions
			printf("0\t"); // display 0
		lim--;
		printf("\n");
	}
}


int main(void)
{
	int ch,row,col,arr[20][20],*list,size;
	while(1)
	{
		printf("Enter Number Of Rows: ");
		scanf("%d",&row);
		printf("Enter Number Of Columns: ");
		scanf("%d",&col);
		validate(row,col);
		printf("\nEnter %d elements of the matrix: \n",row*col);
		getmat(arr,row,col);
		printf("\nEntered Matrix: \n");
		dispmat(arr,row,col);
		printf("\nMenu: ");
		printf("\n1.Upper Triangular Matrix\n2.Lower Triangular Matrix");
		printf("\nEnter Your Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			isuppertri(arr,row,col);
			size=(row*(row+1))/2; //length of 1-D array
			list=(int*)calloc(size,sizeof(int)); //creating 1-D array dynamically
			makeupperlist(list,arr,row,col);
			printf("\nGenerated List: ");
			displist(list,size);
			printf("\nReconstructed Matrix:\n");
			reconsuppmat(list,row);
			prompt();
			break;

			case 2:
			islowertri(arr,row,col);
			size=(row*(row+1))/2; //length of 1-D array
			list=(int*)calloc(size,sizeof(int)); //creating 1-D array dynamically
			makelowerlist(list,arr,row,col);
			printf("\nGenerated List: ");
			displist(list,size);
			printf("\nReconstructed Matrix:\n");
			reconslowmat(list,row);
			prompt(); //ask the user whether to exit 
		    return 0;
		}
	}
}

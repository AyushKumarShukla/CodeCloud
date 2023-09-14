#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*Program To Find Sum Of A Given Set Of Numbers*/

void get_array(int* arr,int num)
{
	int i;
	for(i=0;i<num;i++)
		scanf("%d",&arr[i]);
}

void disp_array(int* arr,int num)
{
	int i;
	for(i=0;i<num;i++)
		printf("%d ",arr[i]);
}

int find_sum(int* arr,int num)
{
	int i,j,sum;
	for(i=0;i<num;i++)
		sum+=arr[i];
	return sum;
}

int main(void)
{
	int num,arr[20],sum;
	printf("To find the sum of a given list of numbers");
	printf("\nEnter the number of items to be added: ");
	scanf("%d",&num);
	printf("Enter %d items to be added: \n",num);
	get_array(arr,num);
	printf("Entered list of items:");
	disp_array(arr,num);
	sum=find_sum(arr,num);
	printf("\nThe Sum Of The Given List Of Numbers Is: %d\n",sum);
	return 0;
}

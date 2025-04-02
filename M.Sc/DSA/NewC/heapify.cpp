#include <vector>
#include <stdio.h>

using namespace std;

void heapify(vector<int>& arr, int n, int i){
	
	//define largest and child indices
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
	
	//compare and set index with largest value
	if(left<n && arr[left] > arr[largest])
		largest = left;
	
	if(right<n && arr[right] > arr[largest])
		largest = right;
	
	//if root is not the largest
	if(largest != i){
		swap(arr[largest],arr[i]);
		heapify(arr,n,largest); //build heap at largest
	}
}

void heapsort(vector<int>& arr){
	int n = arr.size();
	
	//heapify the given array
	for(int i= n-1; i>=0; i--){
		heapify(arr,n,i);
	}
	
	
	for(int i=n-1 ; i>=1 ;i--){
		swap(arr[0],arr[i]); //swap largest(root) in a sequence 0 1 2 ... n
		heapify(arr,i,0); // heapify after each swap at root
	}
}

int main(void){
	vector<int> arr = {9,8,7,6,5,4,3,2,1};
	heapsort(arr);
	for(int val:arr)
		printf("%d\t",val);
	return 0;
}
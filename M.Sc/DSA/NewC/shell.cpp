#include <vector>
#include <stdio.h>

using namespace std;

void shellsort(vector<int>& arr){
	int n = arr.size();
	for(int gap = n/2;gap>0;gap/=2)
		for(int i=gap;i<n;i++)
			for(int j=i;j>=gap && arr[j-gap] > arr[j];j-=gap)
				swap(arr[j],arr[j-gap]);
}

int main(void){
	vector<int> arr = {8,7,6,5,4,3,2,1};
	shellsort(arr);
	for(int val: arr)
		printf("%d ",val);
	return 0;
}
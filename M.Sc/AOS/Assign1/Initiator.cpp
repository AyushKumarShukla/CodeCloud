#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
	ifstream file("matrix1.txt");
	if(!file){
		cerr << "Error opening file" << endl;
		return 1;
	}
	
	vector<vector<int>> adj;
	string line;
	int value;
	int rowcnt, colcnt;
	
	file >> rowcnt;
	file >> colcnt;
	
	while(!file.eof()){
		vector<int> row;
		for(int i=0;i<colcnt;i++){
			file >> value;
			row.push_back(value);
		}
		adj.push_back(row);
	}
	
	cout << "Adjacency Matrix" << endl;
	for( const auto& row : adj){
		for(int val:row){
			cout << val << " ";
		}
		cout << endl;
	}
	return 0;
}
#include <vector>
#include <stdio.h>

using namespace std;

vector<vector<int>> addMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B){
	int n = A.size();
	vector<vector<int>> result(n,vector<int>(n,0));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			result[i][j] = A[i][j] + B[i][j];
		}	
	return result;
}

vector<vector<int>> subMatrix(const vector<vector<int>>& A,const vector<vector<int>>& B){
	int n = A.size();
	vector<vector<int>> result(n,vector<int>(n,0));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			result[i][j] = A[i][j] - B[i][j];
		}	
	return result;
}

vector<vector<int>> strassen(const vector<vector<int>>& A,const vector<vector<int>>& B){
	int n = A.size();
	if(n==1){
		return {{A[0][0] * B[0][0]}};
	}
	
	int mid = n/2;
	
	vector<vector<int>> A11(mid,vector<int>(mid,0)), A12(mid,vector<int>(mid,0)),
						A21(mid,vector<int>(mid,0)), A22(mid,vector<int>(mid,0)),
						B11(mid,vector<int>(mid,0)), B12(mid,vector<int>(mid,0)),
						B21(mid,vector<int>(mid,0)), B22(mid,vector<int>(mid,0));
						
	for(int i=0;i<mid;i++)
		for(int j=0;j<mid;j++){
			A11[i][j]	=	A[i][j];
			A12[i][j]	=	A[i][j+mid];
			A21[i][j]	=	A[i+mid][j];
			A22[i][j]	=	A[i+mid][j+mid];
			
			B11[i][j]	=	B[i][j];
			B12[i][j]	=	B[i][j+mid];
			B21[i][j]	=	B[i+mid][j];
			B22[i][j]	=	B[i+mid][j+mid];
		}
		
 	vector<vector<int>> M1 = strassen(addMatrix(A11, A22), addMatrix(B11, B22));
    vector<vector<int>> M2 = strassen(addMatrix(A21, A22), B11);
    vector<vector<int>> M3 = strassen(A11, subMatrix(B12, B22));
    vector<vector<int>> M4 = strassen(A22, subMatrix(B21, B11));
    vector<vector<int>> M5 = strassen(addMatrix(A11, A12), B22);
    vector<vector<int>> M6 = strassen(subMatrix(A21, A11), addMatrix(B11, B12));
    vector<vector<int>> M7 = strassen(subMatrix(A12, A22), addMatrix(B21, B22));
    
    vector<vector<int>> C1 = addMatrix(subMatrix(addMatrix(M1,M4),M5),M7);
    vector<vector<int>> C2 = addMatrix(M3,M5);
    vector<vector<int>> C3 = addMatrix(M2,M4);
    vector<vector<int>> C4 = addMatrix(subMatrix(addMatrix(M1,M3),M2),M6);
    
    vector<vector<int>> C(n, vector<int>(n,0));
    
    for(int i=0;i<mid;i++)
    	for(int j=0;j<mid;j++){
    		C[i][j] 		=	C1[i][j];
    		C[i][j+mid] 	=	C2[i][j];	 
    		C[i+mid][j] 	=	C3[i][j];
    		C[i+mid][j+mid] =	C4[i][j];
		}
	return C;
}

// Function to print a matrix
void printMatrix(const vector<vector<int>>& M) {
    for (auto row : M) {
        for (int val : row) {
            printf("%d\t",val);
        }
        printf("\n");
    }
}

int main(void){
	vector<vector<int>> A = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
	
	vector<vector<int>> B = {
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1}
	};
	
	vector<vector<int>> C = strassen(A,B);
	printMatrix(C);
	return 0;
}
/*
#include <vector>
#include <iostream>

using std::vector;

// Function to add two matrices
vector<vector<int>> addMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

// Function to subtract two matrices
vector<vector<int>> subMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] - B[i][j];
    return result;
}

// Strassen's Algorithm for Matrix Multiplication
vector<vector<int>> strassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int mid = n / 2;
    vector<vector<int>> A11(mid, vector<int>(mid)), A12(mid, vector<int>(mid)),
                        A21(mid, vector<int>(mid)), A22(mid, vector<int>(mid)),
                        B11(mid, vector<int>(mid)), B12(mid, vector<int>(mid)),
                        B21(mid, vector<int>(mid)), B22(mid, vector<int>(mid));

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    vector<vector<int>> M1 = strassen(addMatrix(A11, A22), addMatrix(B11, B22));
    vector<vector<int>> M2 = strassen(addMatrix(A21, A22), B11);
    vector<vector<int>> M3 = strassen(A11, subMatrix(B12, B22));
    vector<vector<int>> M4 = strassen(A22, subMatrix(B21, B11));
    vector<vector<int>> M5 = strassen(addMatrix(A11, A12), B22);
    vector<vector<int>> M6 = strassen(subMatrix(A21, A11), addMatrix(B11, B12));
    vector<vector<int>> M7 = strassen(subMatrix(A12, A22), addMatrix(B21, B22));

    vector<vector<int>> C11 = addMatrix(subMatrix(addMatrix(M1, M4), M5), M7);
    vector<vector<int>> C12 = addMatrix(M3, M5);
    vector<vector<int>> C21 = addMatrix(M2, M4);
    vector<vector<int>> C22 = addMatrix(subMatrix(addMatrix(M1, M3), M2), M6);

    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }

    return C;
}

// Function to print a matrix
void printMatrix(const vector<vector<int>>& M) {
    for (const auto& row : M) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    vector<vector<int>> A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<vector<int>> B = {
        {17, 18, 19, 20},
        {21, 22, 23, 24},
        {25, 26, 27, 28},
        {29, 30, 31, 32}
    };

    vector<vector<int>> C = strassen(A, B);
    
    std::cout << "Resultant Matrix:\n";
    printMatrix(C);

    return 0;
}

*/
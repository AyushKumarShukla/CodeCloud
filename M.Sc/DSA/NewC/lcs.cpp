#include <iostream>
#include <vector>
#include <string>

using namespace std;

string getLCS(string& x, string& y) {
    int m = x.size();
    int n = y.size();
    
    vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));

    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
            } else {
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }

    // Backtracking to find LCS string
    int i = m, j = n;
    string lcs_str = "";
    
    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {  // If characters match, it's part of LCS
            lcs_str = x[i - 1] + lcs_str;
            i--;
            j--;
        } else if (table[i - 1][j] > table[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs_str;
}

int main() {
    string x = "ABCDGH";
    string y = "AEDFHR";
    
    string lcs_str = getLCS(x, y);
    
    cout << "LCS: " << lcs_str << endl;
    cout << "Length: " << lcs_str.length() << endl;
    
    return 0;
}

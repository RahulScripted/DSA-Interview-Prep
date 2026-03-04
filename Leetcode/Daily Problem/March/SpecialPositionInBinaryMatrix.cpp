// Given an m x n binary matrix mat, return the number of special positions in mat. A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> row(m, 0), col(n, 0);

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1) ans++;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{1,0,0},{0,0,1},{1,0,0}};
    cout << "Count of special positions: " << sol.numSpecial(mat) << endl;
    return 0;
}
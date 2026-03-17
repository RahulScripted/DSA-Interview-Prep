// You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order. Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j]) matrix[i][j] = matrix[i - 1][j] + 1;
            }
        }
        
        int ans = 0;
        for (auto& row : matrix) {
            sort(row.rbegin(), row.rend());
            for (int j = 0; j < n; ++j) {
                ans = max(ans, (j + 1) * row[j]);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{0,0,1},{1,1,1},{1,0,1}};
    cout << "The area of the largest submatrix with rearrangements is: " << sol.largestSubmatrix(matrix) << endl;
}
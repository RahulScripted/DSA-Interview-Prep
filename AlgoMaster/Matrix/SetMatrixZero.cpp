// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        bool firstRowHasZero = false;
        bool firstColHasZero = false;

        for (int c = 0; c < cols; c++) {
            if (matrix[0][c] == 0) {
                firstRowHasZero = true;
                break;
            }
        }

        for (int r = 0; r < rows; r++) {
            if (matrix[r][0] == 0) {
                firstColHasZero = true;
                break;
            }
        }

        for (int r = 1; r < rows; r++) {
            for (int c = 1; c < cols; c++) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }

        for (int r = 1; r < rows; r++) {
            if (matrix[r][0] == 0) {
                for (int c = 1; c < cols; c++) matrix[r][c] = 0;
            }
        }

        for (int c = 1; c < cols; c++) {
            if (matrix[0][c] == 0) {
                for (int r = 1; r < rows; r++) matrix[r][c] = 0;
            }
        }

        if (firstRowHasZero) {
            for (int c = 0; c < cols; c++)  matrix[0][c] = 0;
        }
        
        if (firstColHasZero) {
            for (int r = 0; r < rows; r++) matrix[r][0] = 0;
        }        
    }
};

void print(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
}

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    cout<<"Original matrix: "<<endl;
    print(matrix);
    
    sol.setZeroes(matrix);
    cout<<"After setting zeroes: "<<endl;
    print(matrix);
}
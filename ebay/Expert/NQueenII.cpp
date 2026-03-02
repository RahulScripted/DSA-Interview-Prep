// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other. Given an integer n, return the number of distinct solutions to the n-queens puzzle.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findQueen(int col, int n,  vector<vector<string>>& ans, vector<string>& board, vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal, int& count){

        // Base Case
        if(col == n){
            ans.push_back(board);
            count++;
            return;
        }

        for(int row = 0;row < n; row++){
            if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                findQueen(col + 1, n, ans, board, leftRow, lowerDiagonal, upperDiagonal, count);

                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    int totalNQueens(int n) {
        int count = 0;
        vector<vector<string>>ans;
        vector<string>board(n, string(n, '.'));
        vector<int>leftRow(n, 0);
        vector<int>lowerDiagonal((2 * n - 1), 0);
        vector<int>upperDiagonal((2 * n - 1), 0);
        findQueen(0, n, ans, board, leftRow, lowerDiagonal, upperDiagonal, count);
        return count;
    }
};

int main(){
    int n = 4;
    Solution s;
    cout << "Total number of distinct solutions to the " << n << "-queens puzzle: " << s.totalNQueens(n);
    return 0;
}
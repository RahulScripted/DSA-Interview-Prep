// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other. Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order. Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findQueen(int col, int n,  vector<vector<string>>& ans, vector<string>& board, vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal){

        // Base Case
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0;row < n; row++){
            if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                findQueen(col + 1, n, ans, board, leftRow, lowerDiagonal, upperDiagonal);

                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n, string(n, '.'));
        vector<int>leftRow(n, 0);
        vector<int>lowerDiagonal((2 * n - 1), 0);
        vector<int>upperDiagonal((2 * n - 1), 0);
        findQueen(0, n, ans, board, leftRow, lowerDiagonal, upperDiagonal);
        return ans;
    }
};

int main(){
    int n = 4;
    Solution s;
    cout<<"We can place "<<n<<" queens in the following ways: "<<endl;
    vector<vector<string>> ans = s.solveNQueens(n);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
}
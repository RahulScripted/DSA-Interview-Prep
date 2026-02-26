// You are given an m x n grid where each cell can have one of three values:

//     1 - 0 representing an empty cell,
//     2 - 1 representing a fresh orange, or
//     3 - 2 representing a rotten orange.


// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten. Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int freshOrange = 0;

        vector<vector<int>>visit(rows, vector<int>(cols, 0));
        queue<pair<pair<int, int>, int>> checker;
        for(int i = 0;i < rows;i++){
            for(int j = 0;j < cols;j++){
                if(grid[i][j] == 2){
                    checker.push({{i, j}, 0});
                    visit[i][j] = 2;
                }
                else if(grid[i][j] == 1){
                    freshOrange++;
                    visit[i][j] = 1;
                }
            }
        }

        int timeRequired = 0;
        int rowOperation[] = {-1, 0, 1, 0};
        int colOperation[] = {0, 1, 0, -1};
        int count = 0;
        while(!checker.empty()){
            int findRow = checker.front().first.first;
            int findCol = checker.front().first.second;
            int time = checker.front().second;
            checker.pop();
            timeRequired = max(timeRequired, time);
            for(int i = 0;i < 4;i++){
                int updateRows = findRow + rowOperation[i];
                int updateCols = findCol + colOperation[i];
                if(updateRows >= 0 && updateRows < rows &&
                   updateCols >= 0 && updateCols < cols &&
                   visit[updateRows][updateCols] == 1
                ){
                    checker.push({{updateRows, updateCols}, (time + 1)});
                    visit[updateRows][updateCols] = 2;
                    count++;
                }
            }
        }

        return count == freshOrange ? timeRequired : -1;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << "The minimum number of minutes required is: " << solution.orangesRotting(grid) << endl;
}
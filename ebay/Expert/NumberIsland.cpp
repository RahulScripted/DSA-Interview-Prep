// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int noLand = 0, rows = grid.size(), cols = grid[0].size();
        for(int row = 0;row < rows;row++){
            for(int col = 0;col < cols;col++){
                if(grid[row][col] == '1'){
                    noLand++;
                    findComponents(grid, row, col, rows, cols);
                }
            }
        }
        return noLand;
    }

    void findComponents(vector<vector<char>>& grid, int row, int col, int rows, int cols){
        queue<pair<int, int>>q;
        q.push({row, col});
        grid[row][col] = '0';
        static int rowDirection[4] = {-1, 0, 1, 0};
        static int colDirections[4] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0;i < 4;i++){
                int newRow = r + rowDirection[i];
                int newCol = c + colDirections[i];
                if(newRow >= 0 && newRow < rows &&
                   newCol >= 0 && newCol < cols &&
                   grid[newRow][newCol] == '1'
                ){
                    q.push({newRow, newCol});
                    grid[newRow][newCol] = '0';
                }
            }
        }
    }
};

int main(){
    Solution s;
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    cout << "Number of Islands: " << s.numIslands(grid) << endl;
}
// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water. The area of an island is the number of cells with a value 1 in the island. Return the maximum area of an island in grid. If there is no island, return 0.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>>visited(row, vector<bool>(col, false));
        int maxLand = 0;
        for(int i = 0;i < row; i++){
            for(int j = 0;j < col;j++){
                maxLand = max(maxLand, dfs(grid, visited, i, j, row, col));
            }
        }
        return maxLand;
    }

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col, int rows, int cols){
        if(row < 0 || row >= rows ||
           col < 0 || col >= cols ||
           visited[row][col] ||
           grid[row][col] == 0
        ) return 0;

        visited[row][col] = true;
        return 1 + dfs(grid, visited, row + 1, col, rows, cols) 
                 + dfs(grid, visited, row - 1, col, rows, cols) 
                 + dfs(grid, visited, row, col - 1, rows, cols) 
                 + dfs(grid, visited, row, col + 1, rows, cols);
    }
};
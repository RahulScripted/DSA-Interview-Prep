// You are given an n x n grid where we place some 1 x 1 x 1 cubes that are axis-aligned with the x, y, and z axes. Each value v = grid[i][j] represents a tower of v cubes placed on top of the cell (i, j). We view the projection of these cubes onto the xy, yz, and zx planes. A projection is like a shadow, that maps our 3-dimensional figure to a 2-dimensional plane. We are viewing the "shadow" when looking at the cubes from the top, the front, and the side. Return the total area of all three projections.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int xy = 0, yz = 0, zx = 0;
        for(int i = 0;i < n;i++){
            int maxYZ = 0, maxZX = 0;
            for(int j = 0;j < n;j++){
                xy += grid[i][j] > 0;
                maxYZ = max(maxYZ, grid[i][j]);
                maxZX = max(maxZX, grid[j][i]);
            }
            yz += maxYZ;
            zx += maxZX;
        }
        return xy + yz + zx;
    }
};

int main(){
    Solution sol;
    vector<vector<int>>grid = {{1,2},{3,4}};
    cout<<"The total area of all three projections will be : "<<sol.projectionArea(grid)<<endl;
}
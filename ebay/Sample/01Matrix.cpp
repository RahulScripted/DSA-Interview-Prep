// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell. The distance between two cells sharing a common edge is 1.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visit(n, vector<int>(m, 0));
        vector<vector<int>> distance(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        for(int i = 0;i < n; i++){
            for(int j = 0;j < m;j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    visit[i][j] = 1;
                } else{
                    visit[i][j] = 0;
                }
            }
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            distance[row][col] = steps;
            for(int i = 0;i < 4;i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                if(newRow >= 0 && newRow < n &&
                   newCol >= 0 && newCol < m &&
                   visit[newRow][newCol] == 0
                ){
                    q.push({{newRow, newCol}, steps + 1});
                    visit[newRow][newCol] = 1;
                }
            }
        }
        return distance;
    }
};

void print(vector<vector<int>> mat){
    for(int i = 0;i < mat.size(); i++){
        for(int j = 0;j < mat[0].size(); j++) cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}

int main(){
    Solution s;
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
    cout<<"Orifinal Matrix: "<<endl;
    print(mat);
    vector<vector<int>> ans = s.updateMatrix(mat);
    cout<<"Updated Matrix: "<<endl;
    print(ans);
}
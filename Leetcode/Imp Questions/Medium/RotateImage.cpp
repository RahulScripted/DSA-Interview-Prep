// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        for ( int i = 0 ; i < row ; i++){
            for ( int j = i+1; j< col ; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int k = 0 ; k < row ; k++){
            reverse(matrix[k].begin(), matrix[k].end());
        }
    }
};

void print(vector<vector<int>> matrix){
    for (int i = 0 ; i < matrix.size() ; i++){
        for (int j = 0 ; j < matrix[0].size() ; j++) cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

int main(){
    Solution s;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    cout<<"Original Matrix: "<<endl;
    print(matrix);
    s.rotate(matrix);
    cout<<"Rotated Matrix: "<<endl;
    print(matrix);
}
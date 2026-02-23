// You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill:

//     1 - Begin with the starting pixel and change its color to color.
//     2 - Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
//     3 - Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
//     4 - The process stops when there are no more adjacent pixels of the original color to update.


// Return the modified image after performing the flood fill.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int val, int color){
        int n = image.size(), m = image[0].size();
        if(sr < 0 || sr >= n || sc < 0 || sc >= m || image[sr][sc] != val || image[sr][sc] == color) return;

        image[sr][sc] = color;
        dfs(image, sr - 1, sc, val, color);
        dfs(image, sr + 1, sc, val, color);
        dfs(image, sr, sc - 1, val, color);
        dfs(image, sr, sc + 1, val, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val = image[sr][sc];
        dfs(image, sr, sc, val, color);
        return image;
    }
};

void print(vector<vector<int>>& image){
    for(int i = 0; i < image.size(); i++){
        for(int j = 0; j < image[0].size(); j++){
            cout<<image[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    Solution sol;
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;
    cout << "Before flood fill : " << endl;
    print(image);

    vector<vector<int>> result = sol.floodFill(image, sr, sc, color);
    cout << "After flood fill : " << endl;
    print(result);
}
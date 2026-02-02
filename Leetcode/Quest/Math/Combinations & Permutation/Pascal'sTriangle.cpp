// Given an integer numRows, return the first numRows of Pascal's triangle.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i = 0;i < numRows; i++){
            ans.push_back(vector<int>(i + 1, 1));
            for(int j = 1;j < i;j++) ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int numRows = 5;
    vector<vector<int>> result = sol.generate(numRows);
    cout << "Pascal's Triangle with " << numRows << " rows : " << endl;
    for (const auto& row : result) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
}
// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2. You have the following three operations permitted on a word:

//     1 - Insert a character
//     2 - Delete a character
//     3 - Replace a character






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
        if(i < 0) return j + 1;
        else if(j < 0) return i + 1;
        else if(dp[i][j] != -1) return dp[i][j];
        else if(word1[i] == word2[j]) return dp[i][j] = findMin(i - 1, j - 1, word1, word2, dp);
        return dp[i][j] = 1 + min(
            findMin(i - 1, j - 1, word1, word2, dp),
            min(
                findMin(i - 1, j, word1, word2, dp),
                findMin(i, j - 1, word1, word2, dp)
            )
        );
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return findMin(n - 1, m - 1, word1, word2, dp);
    }
};

int main(){
    Solution sol;
    string word1 = "horse";
    string word2 = "ros";
    cout << "Minimum operations required: " << sol.minDistance(word1, word2) << endl;
    return 0;
}
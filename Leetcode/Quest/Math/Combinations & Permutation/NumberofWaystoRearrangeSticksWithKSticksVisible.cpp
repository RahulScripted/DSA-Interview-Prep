// There are n uniquely-sized sticks whose lengths are integers from 1 to n. You want to arrange the sticks such that exactly k sticks are visible from the left. A stick is visible from the left if there are no longer sticks to the left of it. For example, if the sticks are arranged [1,3,2,5,4], then the sticks with lengths 1, 3, and 5 are visible from the left. Given n and k, return the number of such arrangements. Since the answer may be large, return it modulo 109 + 7.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rearrangeSticks(int n, int k) {
        static const int MOD = 1e9 + 7;
        vector<vector<int>> dp(2, vector<int>(k + 1));
        dp[1][1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= min(i, k); ++j) {
                dp[i % 2][j] = (dp[(i - 1) % 2][j - 1] + int64_t(i - 1) * dp[(i - 1) % 2][j]) % MOD;
            }
        }
        return dp[n % 2][k];
    }
};

int main() {
    Solution sol;
    int n = 5, k = 3;
    cout << "The number of such arrangements will be : " << sol.rearrangeSticks(n, k) << endl;
}
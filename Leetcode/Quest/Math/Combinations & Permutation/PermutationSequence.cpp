// Given n and k, return the kth permutation sequence.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        vector<int> nums(n);
        vector<int> fact(n + 1, 1);
        iota(nums.begin(), nums.end(), 1);

        for (int i = 2; i <= n; ++i) fact[i] = fact[i - 1] * i;
        --k;

        for (int i = n - 1; i >= 0; --i) {
            const int j = k / fact[i];
            k %= fact[i];
            ans += to_string(nums[j]);
            nums.erase(nums.begin() + j);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int n = 3, k = 3;
    cout << "The " << k << "th permutation sequence of numbers from 1 to " << n << " is: " << sol.getPermutation(n, k) << endl;

    n = 4, k = 9;
    cout << "The " << k << "th permutation sequence of numbers from 1 to " << n << " is: " << sol.getPermutation(n, k) << endl;

    n = 3, k = 1;
    cout << "The " << k << "th permutation sequence of numbers from 1 to " << n << " is: " << sol.getPermutation(n, k) << endl;
}
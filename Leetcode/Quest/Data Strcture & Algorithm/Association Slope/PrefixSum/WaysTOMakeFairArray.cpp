// You are given an integer array nums. You can choose exactly one index (0-indexed) and remove the element. Notice that the index of the elements may change after the removal. Return the number of indices that you could choose such that after the removal, nums is fair.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int s1 = 0, s2 = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            s1 += i % 2 == 0 ? nums[i] : 0;
            s2 += i % 2 == 1 ? nums[i] : 0;
        }
        int t1 = 0, t2 = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            ans += i % 2 == 0 && t2 + s1 - t1 - v == t1 + s2 - t2;
            ans += i % 2 == 1 && t2 + s1 - t1 == t1 + s2 - t2 - v;
            t1 += i % 2 == 0 ? v : 0;
            t2 += i % 2 == 1 ? v : 0;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 1, 6, 4};
    cout << "Number of ways to make fair array: " << sol.waysToMakeFair(nums) << endl;
    return 0;
}
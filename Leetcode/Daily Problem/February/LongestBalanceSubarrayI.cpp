// You are given an integer array nums. A subarray is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers. Return the length of the longest balanced subarray.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            unordered_set<int> vis;
            int cnt[2]{};
            for (int j = i; j < n; ++j) {
                if (!vis.contains(nums[j])) {
                    vis.insert(nums[j]);
                    ++cnt[nums[j] & 1];
                }
                if (cnt[0] == cnt[1]) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    cout << "The length of the longest balanced subarray will be : " << sol.longestBalanced(nums) << endl;
}
// Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array. Return the length of the smallest subarray that you need to remove, or -1 if it's impossible. A subarray is defined as a contiguous block of elements in the array.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int k = 0;
        for (int& x : nums) k = (k + x) % p;
        if (k == 0) return 0;

        unordered_map<int, int> last;
        last[0] = -1;
        int n = nums.size();
        int ans = n;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur = (cur + nums[i]) % p;
            int target = (cur - k + p) % p;
            if (last.count(target)) ans = min(ans, i - last[target]);
            last[cur] = i;
        }
        return ans == n ? -1 : ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 1, 4, 2};
    int p = 6;
    cout << "Needs to remove: " << sol.minSubarray(nums, p) << endl;
    return 0;
}
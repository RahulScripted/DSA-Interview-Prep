// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i = 0;i < n;i++) ans ^= nums[i];
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "The single number is: " << sol.singleNumber(nums) << endl;
}
// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % 2 != 0) return false;

        int target = total / 2;
        vector<bool>dp(target + 1, false);
        dp[0] = true;

        for(int num : nums){
            for(int i = target ;i >= num; i--){
                if(dp[i]) continue;
                if(dp[i - num]) dp[i] = true;
                if(dp[target]) return true;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 5, 11, 5};
    cout << "Can partition? : " << (sol.canPartition(nums) ? "True" : "False") << endl;
    return 0;
}
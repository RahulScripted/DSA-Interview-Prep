// Given an integer array nums, find the subarray with the largest sum, and return its sum.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), ans = nums[0], total = 0;
        for(int i = 0;i < n; i++){
            if(total < 0) total = 0;
            total += nums[i];
            ans = max(ans, total);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Maximum Subarray Sum: " << s.maxSubArray(nums) << endl;
    return 0;
}
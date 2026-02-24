// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), sum = 0, maxLen = 0;
        unordered_map<int, int>seen{{0, -1}};
        for(int i = 0;i < n;i++){
            sum += nums[i] == 1 ? 1 : -1;
            if(seen.count(sum)) maxLen = max(maxLen, i - seen[sum]);
            else seen[sum] = i;
        }
        return maxLen;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {0,1,0};
    cout << "Maximum length of contiguous subarray with equal 0 and 1: " << sol.findMaxLength(nums) << endl;
}
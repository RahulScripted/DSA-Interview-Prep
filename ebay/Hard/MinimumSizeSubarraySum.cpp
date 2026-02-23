// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0, sum = 0, minLen = INT_MAX;
        while(right < n){
            sum += nums[right];
            while(sum >= target){
                minLen = min(minLen, (right - left + 1));
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    cout << "Minimum size of subarray is: " << sol.minSubArrayLen(target, nums) << endl;
}
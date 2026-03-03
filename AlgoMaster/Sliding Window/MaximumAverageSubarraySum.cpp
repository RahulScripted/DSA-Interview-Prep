// You are given an integer array nums consisting of n elements, and an integer k. Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currSum = 0, maxSum = 0;
        for (int i = 0; i < k; i++) currSum += nums[i];
        maxSum = currSum;
        
        for (int i = k; i < nums.size(); i++) {
            currSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, currSum);
        }
        
        return maxSum / k;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    cout << "Maximum average: " << sol.findMaxAverage(nums, k) << endl;
    return 0;
}
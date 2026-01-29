// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int actualSum = n * (n + 1) / 2;
        int currSum = 0;
        for(int i = 0;i < n; i++) currSum += nums[i];
        return actualSum - currSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {3,0,1};
    cout << "Missing Number is : " << sol.missingNumber(nums1) << endl;

    vector<int> nums2 = {0,1};
    cout << "Missing Number is : " << sol.missingNumber(nums2) << endl;

    vector<int> nums3 = {9,6,4,2,3,5,7,0,1};
    cout << "Missing Number is : " << sol.missingNumber(nums3) << endl;
}
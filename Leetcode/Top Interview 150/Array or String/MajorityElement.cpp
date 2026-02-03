// Given an array nums of size n, return the majority element. The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, majority = 0;
        
        for (int n : nums) {
            if (majority == 0) res = n;
            majority += n == res ? 1 : -1;
        }
        return res;

        // Brute-force Approach
        // sort(nums.begin(),nums.end());
        // return nums[nums.size() / 2];
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,2,3};
    cout << "Majority Element is: " << s.majorityElement(nums) << endl;

    nums = {2,2,1,1,1,2,2};
    cout << "Majority Element is: " << s.majorityElement(nums) << endl;
}
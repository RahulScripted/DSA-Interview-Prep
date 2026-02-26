// Given an integer array nums, handle multiple queries of the following type - Calculate the sum of the elements of nums between indices left and right inclusive where left <= right. Implement the NumArray class:

//     1 - NumArray(int[] nums) Initializes the object with the integer array nums.
//     2 - int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).






#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        prefix.push_back(nums[0]);
        for(int i=1;i<nums.size();i++) {
            prefix.push_back(nums[i]+prefix[i-1]);
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0) return prefix[right];
        return prefix[right]-prefix[left-1];
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray* obj = new NumArray(nums);
    cout<<obj->sumRange(0, 2)<<endl;
    cout<<obj->sumRange(2, 5)<<endl;
    cout<<obj->sumRange(0, 5)<<endl;
    return 0;
}
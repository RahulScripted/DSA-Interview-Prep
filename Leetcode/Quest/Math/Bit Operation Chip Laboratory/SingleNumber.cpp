// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one. You must implement a solution with a linear runtime complexity and use only constant extra space.




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

int main(){
    Solution sol;
    vector<int>nums = {2, 2, 1};
    cout<<"Single number is : "<<sol.singleNumber(nums);
}
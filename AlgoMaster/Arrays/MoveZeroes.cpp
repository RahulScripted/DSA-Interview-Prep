// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), isZero = 0;
        for(int i = 0;i < n;i++){
            if(nums[i] != 0){
                swap(nums[i], nums[isZero]);
                isZero++;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums);
    cout<<"After moving Zeros : ";
    for(int num : nums) cout << num << " ";
}
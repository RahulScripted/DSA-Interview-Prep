// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k. The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(nums.empty()) return 0;
        int i = 1;
        for(int j = 1; j < n; j++){
            if(nums[j] != nums[i - 1]){
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int k = sol.removeDuplicates(nums);
    cout << "The number of unique elements in the array is : " << k << endl;
    cout << "The unique elements in the array are : ";
    for(int i = 0; i < k; i++) cout << nums[i] << " ";
    cout << endl;
    return 0;
}
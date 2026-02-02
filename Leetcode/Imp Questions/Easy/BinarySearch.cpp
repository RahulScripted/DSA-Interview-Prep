// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1; 
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    if(sol.search(nums, target) != -1)cout << "Element found at index: " << sol.search(nums, target) << endl;
    else cout << "Element not found in the array." << endl;

    nums = {-1,0,3,5,9,12};
    target = 2;
    if(sol.search(nums, target) != -1)cout << "Element found at index: " << sol.search(nums, target) << endl;
    else cout << "Element not found in the array." << endl;
}
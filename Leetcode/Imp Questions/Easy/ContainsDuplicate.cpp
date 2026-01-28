// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        return numSet.size() < nums.size(); 
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 1};
    cout << (sol.containsDuplicate(nums1) ? "true" : "false") << endl;

    vector<int> nums2 = {1, 2, 3, 4};
    cout << (sol.containsDuplicate(nums2) ? "true" : "false") << endl;

    vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << (sol.containsDuplicate(nums3) ? "true" : "false") << endl;
}
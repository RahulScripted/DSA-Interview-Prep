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
    Solution solution;
    vector<int> nums = {1, 2, 3, 1};
    bool result = solution.containsDuplicate(nums);
    cout << "Contains duplicate: " << (result ? "true" : "false") << endl; 
    return 0;
}
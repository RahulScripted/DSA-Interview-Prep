// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) set.erase(nums[i - k - 1]);
            if (set.count(nums[i])) return true;
            set.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    cout << "Contains Duplicate : " << (sol.containsNearbyDuplicate(nums, k) ? "True" : "False") << endl;
}
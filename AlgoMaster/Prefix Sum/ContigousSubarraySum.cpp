// Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise. A good subarray is a subarray where:

//     1 - Its length is at least two, and
//     2 - The sum of the elements of the subarray is a multiple of k.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefix = 0;
        unordered_map<int, int> prefixToIndex{{0, -1}};

        for (int i = 0; i < nums.size(); ++i) {
            prefix += nums[i];
            if (k != 0) prefix %= k;
            if (const auto it = prefixToIndex.find(prefix);
                it != prefixToIndex.cend()) {
                if (i - it->second > 1)
                return true;
            } 
            else prefixToIndex[prefix] = i;
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;
    cout << "Result: " << (sol.checkSubarraySum(nums, k) ? "True" : "False") << endl;
}
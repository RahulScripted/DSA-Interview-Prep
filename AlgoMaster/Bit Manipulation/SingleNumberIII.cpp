// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(2);
        int index = 0;

        for (int i = 0; i < n; ++i) {
            bool found = false;
            for (int j = 0; j < n; ++j) {
                if (i != j && nums[i] == nums[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result[index++] = nums[i];
                if (index == 2) break;
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> result = solution.singleNumber(nums);
    cout << "The two single numbers are: ";
    for (int num : result) cout << num << " ";
}
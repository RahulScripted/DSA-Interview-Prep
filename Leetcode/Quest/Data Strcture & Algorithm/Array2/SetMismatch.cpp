// You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number. You are given an integer array nums representing the data status of this set after the error. Find the number that occurs twice and the number that is missing and return them in the form of an array.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicate;

        for (const int num : nums){
            if (nums[abs(num) - 1] < 0) duplicate = abs(num);
            else nums[abs(num) - 1] *= -1;
        }

        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] > 0) return {duplicate, i + 1};
        }

        throw;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2, 4};
    vector<int> result = sol.findErrorNums(nums);
    cout << "Duplicate: " << result[0] << ", Missing: " << result[1] << endl;

    nums = {1, 1};
    result = sol.findErrorNums(nums);
    cout << "Duplicate: " << result[0] << ", Missing: " << result[1] << endl;
}
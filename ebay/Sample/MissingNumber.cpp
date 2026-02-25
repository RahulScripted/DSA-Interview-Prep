// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), currentSum = 0;
        int actualSum = (n * (n + 1)) / 2;
        for(int num : nums) currentSum += num;
        return (actualSum - currentSum); 
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 0, 1};
    cout << "Missing number: " << sol.missingNumber(nums) << endl;
}
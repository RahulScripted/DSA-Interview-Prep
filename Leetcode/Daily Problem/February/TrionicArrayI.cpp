// You are given an integer array nums of length n. An array is trionic if there exist indices 0 < p < q < n − 1 such that:

//     1 - nums[0...p] is strictly increasing,
//     2 - nums[p...q] is strictly decreasing,
//     3 - nums[q...n − 1] is strictly increasing.

// Return true if nums is trionic, otherwise return false.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size(), peak = -1, valley = n;

        for (int i = 0; i < n - 1; i++) {
            if (peak == -1 && nums[i] >= nums[i + 1]) peak = i;
            if (valley == n && nums[n - 1 - i] <= nums[n - 2 - i]) valley = n - 1 - i;
            if (peak > 0 && valley < n - 1) return peak < valley && isDecreasing(nums, peak, valley);
        }

        return false;
    }

    bool isDecreasing(vector<int>& nums, int a, int b) {
        for (int i = a; i < b; i++){
            if (nums[i] <= nums[i + 1]) return false;
        }
        
        return true;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 3, 1};
    if(s.isTrionic(nums) == true) cout << "Yes, it's trionic" << endl;
    else cout << "No, it's not trionic" << endl;

    nums = {2, 1, 3};
    if(s.isTrionic(nums) == true) cout << "Yes, it's trionic" << endl;
    else cout << "No, it's not trionic" << endl;
}
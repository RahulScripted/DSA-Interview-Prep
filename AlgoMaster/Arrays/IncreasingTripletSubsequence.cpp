// Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for(int n : nums) {
            if(n <= min1) min1 = n;
            else if(n <= min2) min2 = n;
            else return true;
        }
        return false; 
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "Exists increasing triplet? " << (sol.increasingTriplet(nums) ? "Yes" : "No") << endl;
    return 0;
}
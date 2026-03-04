// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night. Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int maxRob = 0, prevRob = 0;
        for(int num : nums){
            int temp = max(maxRob, prevRob + num);
            prevRob = maxRob;
            maxRob = temp;
        }
        return maxRob;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,1};
    cout << "Maximum amount that can be robbed: " << sol.rob(nums) << endl;
}
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Optimal Approach
        int n = nums.size();
        unordered_map<int, int>mp;
        for(int i = 0;i < n;i++){
            int current = nums[i];
            int required = target - current;
            if(mp.find(required) != mp.end()) return {i, mp[required]};
            mp[current] = i;
        }
        return {-1, -1};

        // Brutee-force Approach
        // int n = nums.size();
        // for(int i = 0;i < n;i++){
        //     for(int j = (i + 1);j < n;j++){
        //         if(nums[i] + nums[j] == target) return {i, j};
        //     }
        // }
        // return {-1, -1};
    }
};

int main(){
    Solution s;
    vector<int>nums = {2, 7, 11, 15};
    int target = 9;
    vector<int>ans = s.twoSum(nums, target);
    cout<<"Indices of the two numbers such that they add up to target are: ";
    for(auto i: ans) cout << i << " ";
}
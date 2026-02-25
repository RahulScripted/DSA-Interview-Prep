// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Optimal
        int n = nums.size();
        unordered_map<int, int>mp;
        for(int i = 0;i < n;i++){
            int current = nums[i];
            int required = target - current;
            if(mp.find(required) != mp.end()) return {mp[required], i};
            mp[current] = i;
        }
        return {-1, -1};

        // Better than Brute-force
        // int n = nums.size();
        // for(int i = 0;i < n;i++){
        //     for(int j = (i + 1);j < n;j++){
        //         if(nums[i] + nums[j] == target) return {i, j};
        //     }
        // }
        // return {-1, -1};

        // Brute-force
        // int n = nums.size();
        // for(int i = 0;i < n;i++){
        //     for(int j = 0;j < n;j++){
        //         if(i == j) continue;
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
    cout << "Indices of the two numbers such that they add up to " << target << ": ";
    for(int i : ans) cout << i << " ";
}
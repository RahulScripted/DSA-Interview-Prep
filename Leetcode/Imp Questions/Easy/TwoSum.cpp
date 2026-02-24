// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.




#Include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Optimized One
        map<int, int>mp;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            int current = nums[i];
            int required = target - nums[i];
            if(mp.find(required) != mp.end()) return {mp[required], i};
            mp[current] = i; 
        }
        return {-1, -1};

        // Brute-force Approach
        // int n = nums.size();
        // for(int i = 0;i < n;i++){
        //     for(int j = 0;j < n;j++){
        //         if(i == j) continue;
        //         if(nums[i] + nums[j] == target) return {i, j};
        //     }
        // }
        // return {-1, - 1};
    }
};

int main(){
    Solution s;
    vector<int>nums = {2, 7, 11, 15};
    int target = 9;
    vector<int>ans = s.twoSum(nums, target);
    cout<<"Indices of the two numbers such that they add up to " << target << " are: ";
    for(auto i: ans) cout << i << " ";
}
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // More Optimal if "yes" or 'No' instead of return the idx
        // sort(nums.begin(), nums.end());
        // int n = nums.size(), left = 0, right = n - 1;
        // while(left < right){
        //     if(nums[left] + nums[right] == target) return true;
        //     else if(nums[left] + nums[right] < target) left++;
        //     else right--;
        // }
        // return false;

        // Optimal Approach
        map<int, int>mp;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            int current = nums[i];
            int required = target - current;
            if(mp.find(required) != mp.end()) return {mp[required], i};
            mp[current] = i;
        }
        return {-1, -1};


        // Slightly better than Brute-force Algo
        // int n = nums.size();
        // for(int i = 0;i < n;i++){
        //     for(int j = (i + 1);j < n;j++){
        //         else if(nums[i] + nums[j] == target) return {i, j};
        //     }
        // }
        // return {-1, -1};


        // Brute-force Algo
        // int n = nums.size();
        // for(int i = 0;i < n;i++){
        //     for(int j = 0;j < n;j++){
        //         if(i == j) continue;
        //         else if(nums[i] + nums[j] == target) return {i, j};
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
    cout<<"Indices of the two numbers such that they add up to "<<target<<" are: ";
    for(auto i : ans) cout << i << " ";
}
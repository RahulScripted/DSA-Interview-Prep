// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Time complexity -> O(n) && Space Complexity -> O(1)
        int n = nums.size(); 
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (const int num : nums) sum += num >> i & 1;
            sum %= 3;
            ans |= sum << i;
        }

        return ans;

        // Time complexity -> O(n) && Space Complexity -> O(n)
        // int n = nums.size(); 
        // unordered_map<int, int>mp;
        // for(int i = 0;i < n;i++) mp[nums[i]]++;
        // for(auto& entry : mp){
        //     if(entry.second == 1) return entry.first;
        // }
        // return -1;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2, 2, 3, 2};
    cout << "Single Number: " << sol.singleNumber(nums) << endl;
    return 0;
}
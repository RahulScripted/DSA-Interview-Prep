// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k. A subarray is a contiguous non-empty sequence of elements within an array.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Optimal
        int n = nums.size(), ans = 0;
        vector<int>prefix(n);
        prefix[0] = nums[0];

        for(int i = 1; i < n;i++) prefix[i] = nums[i] + prefix[i - 1];
        unordered_map<int, int>freq;
        for(int i = 0; i < n;i++){
            if(prefix[i] == k) ans++;
            if(freq.find(prefix[i] - k) != freq.end()) ans += freq[prefix[i] - k];
            freq[prefix[i]]++;
        }
        return ans;

        // Brute-force
        // int n = nums.size(), ans = 0;
        // for(int i = 0;i < n;i++){
        //     int sum = nums[i];
        //     if(sum == k) ans++;
        //     for(int j = (i + 1); j < n;j++){
        //         sum += nums[j];
        //         if(sum == k) ans++;
        //     }
        // }
        // return ans;
    }
};

int main(){
    Solution sol;
    vector<int>nums = {1, 2, 3};
    int k = 3;
    cout<<"Number of subarrays : "<<sol.subarraySum(nums, k);
}
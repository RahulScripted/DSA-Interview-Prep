// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        int count = 0;
        int prefixSum = 0;
        unordered_map<int, int> prefixMap;
        prefixMap[0] = 1;

        for (int num : nums) {
            prefixSum += num;
            int mod = prefixSum % k;
            if (mod < 0) mod += k;
            if (prefixMap.find(mod) != prefixMap.end()) {
                count += prefixMap[mod];
                prefixMap[mod] += 1;
            } else prefixMap[mod] = 1;
        }
        
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;
    cout << "Number of subarrays divisible by " << k << ": " << sol.subarraysDivByK(nums, k) << endl;
}
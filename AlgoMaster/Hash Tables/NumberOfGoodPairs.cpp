// Given an array of integers nums, return the number of good pairs. A pair (i, j) is called good if nums[i] == nums[j] and i < j.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> pairs;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (pairs.find(nums[i]) != pairs.end()) count += pairs[nums[i]];
            pairs[nums[i]] = pairs[nums[i]] + 1;
        }

        return count;        
    }
};

int main(){
    Solution sol;
    vector<int>nums = {1,2,3,1,1,3};
    cout<<"Number of good pairs : "<<sol.numIdenticalPairs(nums)<<endl;
}
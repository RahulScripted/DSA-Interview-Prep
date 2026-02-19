// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unoredered_map<int,int> count;
        for(int num : nums) count[num]++;

        vector<vector<int>> bucket(nums.size()+1);
        for(auto& entry : count) bucket[entry.second].push_back(entry.first);

        vector<int> res;
        for(int i = bucket.size()-1; i >= 0; i--){
            for(int num : bucket[i]){
                res.push_back(num);
                if(res.size() == k) return res;
            }
        }

        return {};
    }
};
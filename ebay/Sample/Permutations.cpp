// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }

    void backtrack(vector<int>& nums, int start, vector<vector<int>>& res){
        if(start == nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i = start; i < nums.size(); i++){
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }
};

void print(const vector<int>& nums){
    for(int num : nums)cout<<num<<" ";
    cout<<endl;
}

void printAns(const vector<vector<int>>& ans){
    for(const auto& perm : ans) print(perm);
}

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3};
    cout<<"Original array: ";
    print(nums);
    vector<vector<int>> result = sol.permute(nums);
    cout<<"Permutations: "<<endl;
    printAns(result);
}
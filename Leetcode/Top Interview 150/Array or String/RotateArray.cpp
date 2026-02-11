// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

void print(vector<int>& nums){
    for(int num : nums) cout<<num<<" ";
}

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    cout<<"Before rotating : ";
    print(nums);
    cout<<endl;

    cout<<"After rotating : ";
    sol.rotate(nums, k);
    print(nums);
}
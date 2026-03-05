// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].




#include <bits/stdc++.h>    
using namespace std;    

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n, 1);
        
        int left = 1;
        for(int i = 0;i < n;i++){
            result[i] *= left;
            left *= nums[i];
        }

        int right = 1;
        for(int i = (n - 1); i >= 0; i--){
            result[i] *= right;
            right *= nums[i];
        }

        return result;
    }
};

void print(vector<int> &nums){
    for(int i = 0; i < nums.size(); i++) cout<<nums[i]<<" ";
    cout<<endl;
}

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    cout<<"Input array: ";
    print(nums);
    vector<int> result = sol.productExceptSelf(nums);
    cout<<"After calculating the product of array except itself: ";
    print(result);
}
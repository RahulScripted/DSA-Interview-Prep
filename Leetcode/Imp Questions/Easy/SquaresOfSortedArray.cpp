// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);

        int left=0;
        int right=n-1;
        int pos=n-1;

        while(left<=right){
            if(abs(nums[left])>abs(nums[right])){
                result[pos]=nums[left]*nums[left];
                left++;
            } else{
                result[pos]=nums[right]*nums[right];
                right--;
            }

            pos--;
        }

        return result;
    }
};

void print(vector<int> &nums){
    for(int i: nums) cout<<i<<" ";
    cout<<endl;
}

int main(){
    Solution sol;
    vector<int> nums = {-4,-1,0,3,10};
    cout<<"Before squaring: ";
    print(nums);
    vector<int> result = sol.sortedSquares(nums);
    cout<<"After squaring: ";
    print(result);
}
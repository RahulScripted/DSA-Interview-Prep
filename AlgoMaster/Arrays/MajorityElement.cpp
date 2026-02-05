// Given an array nums of size n, return the majority element. The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, majority = 0;
        for(int num : nums){
            if(majority == 0) res = num;
            majority += num == res ? 1 : -1;
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << "Majority Element is : " << sol.majorityElement(nums) << endl;
}
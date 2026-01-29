// Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i]. Return the answer in an array.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(101,0);

        for(auto val : nums) res[val]++;

        for(int  i = 1;i < 101;i++) res[i] += res[i-1];

        vector<int>ans;
        for(auto val : nums){
            if(val == 0) ans.push_back(0);
            else ans.push_back(res[val-1]);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {8,1,2,2,3};
    vector<int> result = sol.smallerNumbersThanCurrent(nums);
    for(int val : result) cout << val << " ";

    nums = {6,5,4,8};
    result = sol.smallerNumbersThanCurrent(nums);
    for(int val : result) cout << val << " ";
}
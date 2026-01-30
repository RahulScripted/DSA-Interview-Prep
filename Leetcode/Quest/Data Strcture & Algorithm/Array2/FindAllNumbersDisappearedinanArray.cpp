// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        for(const int num: nums){
            const int index = abs(num) - 1;
            nums[index] = -abs(nums[index]);
        }

        for(int i = 0;i < nums.size();i++){
            if(nums[i] > 0) ans.push_back(i + 1);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> result = sol.findDisappearedNumbers(nums);
    
    cout << "Disappeared numbers: ";
    for (int num : result) cout << num << " ";
}
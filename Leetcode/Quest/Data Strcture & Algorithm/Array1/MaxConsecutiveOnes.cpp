// Given a binary array nums, return the maximum number of consecutive 1's in the array.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0, count = 0;
        for(int num: nums){
            if(num == 1) count++;
            else count = 0;
            maxi = max(count, maxi);
        }
        return maxi;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,0,1,1,1};
    cout << "Max consecutive ones: " << sol.findMaxConsecutiveOnes(nums) << endl;

    nums = {1,0,1,1,0,1};
    cout << "Max consecutive ones: " << sol.findMaxConsecutiveOnes(nums) << endl;
}
// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, end = 0, maxCount = 0, zeroCount = 0, n = nums.size() - 1;
        while(end <= n){
            if(nums[end] == 1) end++;
            else if(nums[end] == 0 && zeroCount <= k){
                zeroCount++;
                end++;
            }
            while(zeroCount > k){
                if(nums[start] == 0) zeroCount--;
                start++;
            }
            maxCount = max(maxCount, end - start);
        }
        return maxCount;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout << "Maximum consecutive 1's: " << s.longestOnes(nums, k) << endl;
}
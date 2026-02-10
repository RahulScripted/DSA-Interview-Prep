// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val. Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things: Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums. Return k.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (const int num : nums)
        if (num != val) nums[i++] = num;
        return i;
    }
};

int main(){
    Solution sol;
    vector<int>nums = {3,2,2,3};
    int val = 3;
    cout<<"The number of elements in nums which are not equal to val will be : "<<sol.removeElement(nums, val)<<endl;
}
// Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn]. Return the array in the form [x1,y1,x2,y2,...,xn,yn].




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans;
        for(int i = 0;i < n;i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[i + n]);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,5,1,3,4,7};
    int n = 3;
    vector<int> result = sol.shuffle(nums, n);
    cout<<"After Shuffling: ";
    for(int i : result)  cout << i << " ";

    nums = {1,2,3,4,4,3,2,1};
    n = 4;
    result = sol.shuffle(nums, n);
    cout<<"After Shuffling: ";
    for(int i : result)  cout << i << " ";
}
// You are given an integer array nums and an integer k. An array is considered balanced if the value of its maximum element is at most k times the minimum element. You may remove any number of elements from nums​​​​​​​ without making it empty. Return the minimum number of elements to remove so that the remaining array is balanced.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxLen = 0;
        int i = 0;

        for(int j = 0;j < n; j++){
            while((long long)nums[j] > (long long)nums[i] * k) i++;
            maxLen = max(maxLen, j - i + 1);
        }
        return (n - maxLen);
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;
    cout << "Minimum removals to balance the array: " << s.minRemoval(nums, k) << endl;
}
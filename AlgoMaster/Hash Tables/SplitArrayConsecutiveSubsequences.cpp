// You are given an integer array nums that is sorted in non-decreasing order. Determine if it is possible to split nums into one or more subsequences such that both of the following conditions are true:

//     1 - Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
//     2 - All subsequences have a length of 3 or more.

// Return true if you can split nums according to the above conditions, or false otherwise.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> left, end;
        for (int i: A)  left[i]++;

        for (int i: A) {
            if (left[i] == 0) continue;
            left[i]--;
            if (end[i - 1] > 0) {   
                end[i - 1]--;
                end[i]++;
            } else if (left[i + 1] > 0 && left[i + 2] > 0) {
                left[i + 1]--;
                left[i + 2]--;
                end[i + 2]++;
            } else return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,3,4,5};
    cout << "Can Split into Consecutive Subsequences? " << (sol.isPossible(nums) ? "Yes" : "No") << endl;
    return 0;
}
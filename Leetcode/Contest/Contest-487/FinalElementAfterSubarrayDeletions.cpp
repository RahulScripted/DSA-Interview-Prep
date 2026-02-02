// You are given an integer array nums. Two players, Alice and Bob, play a game in turns, with Alice playing first.

//     1 - In each turn, the current player chooses any subarray nums[l..r] such that r - l + 1 < m, where m is the current length of the array.
//     2 - The player receives points equal to the sum of the elements in the chosen subarray. The selected subarray is removed, and the remaining elements are concatenated to form the new array.
//     3 - The game continues until only one element remains.

// Alice aims to maximize the final element, while Bob aims to minimize it. Assuming both play optimally, return the value of the final remaining element.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums.front(), nums.back()); 
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {5,3,1,4,2};
    cout << "The value of the final remaining element is: " << sol.finalElement(nums1) << endl;

    vector<int> nums2 = {2,2,2};
    cout << "The value of the final remaining element is: " << sol.finalElement(nums2) << endl;
}
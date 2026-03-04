// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>numSet(nums.begin(),nums.end());
        int longest = 0;
        for(int num : numSet){
            if(numSet.find(num - 1) == numSet.end()){
                int length = 1;
                while(numSet.find(num + length) != numSet.end()) length++;
                longest = max(longest, length);
            }
        }
        return longest;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Length of longest consecutive sequence: " << sol.longestConsecutive(nums) << endl; 
    return 0;
}
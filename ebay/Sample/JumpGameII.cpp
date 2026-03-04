// You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0. Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

//     1 - 0 <= j <= nums[i] and
//     2 - i + j < n

// Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int near = 0, far = 0, jumps = 0, n = nums.size() - 1;

        while (far < n) {
            int farthest = 0;
            for (int i = near; i <= far; i++) farthest = max(farthest, i + nums[i]);
            near = far + 1;
            far = farthest;
            jumps++;
        }

        return jumps;        
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Minimum jumps required: " << sol.jump(nums) << endl;
    return 0;
}
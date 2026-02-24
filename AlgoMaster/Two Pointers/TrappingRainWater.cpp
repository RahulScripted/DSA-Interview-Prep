// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int ans = 0;
        int l = 0;
        int r = height.size() - 1;
        int maxL = height[l];
        int maxR = height[r];

        while (l < r){
            if (maxL < maxR) {
                ans += maxL - height[l];
                maxL = max(maxL, height[++l]);
            } else {
                ans += maxR - height[r];
                maxR = max(maxR, height[--r]);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped water: " << sol.trap(height) << endl;
    return 0;
}
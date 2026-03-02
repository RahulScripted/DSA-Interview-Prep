// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int left = 0, right = height.size() - 1, ans = 0;
        int maxLeft = height[left], maxRight = height[right];

        while(left < right){
            if(maxLeft < maxRight){
                ans += maxLeft - height[left];
                maxLeft = max(maxLeft, height[++left]);
            } else{
                ans += maxRight - height[right];
                maxRight = max(maxRight, height[--right]);
            }
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped water: " << sol.trap(height) << endl;
    return 0;
}
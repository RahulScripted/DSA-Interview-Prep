// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n = heights.size(), maxHeight = 0;

        for(int i = 0;i <= n;i++){
            while(!st.empty() && ((i == n )|| heights[st.top()] >= heights[i])){
                int height = heights[st.top()];
                st.pop();

                int width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;
                maxHeight = max(maxHeight, (width * height));
            }
            st.push(i);
        }

        return maxHeight;
    }
};

int main(){
    Solution sol;
    vector<int> heights = {2,1,5,6,2,3};
    cout << "Largest Rectangle Area: " << sol.largestRectangleArea(heights) << endl;
}
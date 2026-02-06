// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int>stk;
        vector<int>ans(n);

        for(int i = (n - 1); i >= 0; i--){
            while(!stk.empty() && temperatures[stk.top()] <= temperatures[i]) stk.pop();
            if(!stk.empty()) ans[i] = stk.top() - i;
            stk.push(i);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = sol.dailyTemperatures(temperatures);
    
    cout<<"The number of days you have to wait : ";
    for(int days : result) cout << days << " ";
}
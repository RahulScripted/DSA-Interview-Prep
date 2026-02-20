// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), result = 0;

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });
        int prev = intervals[0][1];
        for(int i = 1;i < n;i++){
            if(prev > intervals[i][0]) result++;
            else prev = intervals[i][1];
        }

        return result;
    }
};

int main(){
    Solution s;
    vector<vector<int>> intervals{{1,2},{2,3},{3,4},{1,3}};
    cout<<"We can reomve "<<s.eraseOverlapIntervals(intervals)<<" elements";
}
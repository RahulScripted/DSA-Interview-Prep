// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                int cnt = 2;
                for (int k = j + 1; k < n; ++k) {
                    int x3 = points[k][0], y3 = points[k][1];
                    int a = (y2 - y1) * (x3 - x1);
                    int b = (y3 - y1) * (x2 - x1);
                    cnt += a == b;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};
    cout<<"The maximum number of points that lie on the same straight line will be : "<<sol.maxPoints(points);
}
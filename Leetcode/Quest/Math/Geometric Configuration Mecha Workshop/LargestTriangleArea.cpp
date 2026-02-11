// Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points. Answers within 10-5 of the actual answer will be accepted.




#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  double largestTriangleArea(vector<vector<int>>& points) {
    double ans = 0;

    for (const vector<int>& A : points){
      for (const vector<int>& B : points){
        for (const vector<int>& C : points){
          ans = max(ans, 0.5 * abs((B[0] - A[0]) * (C[1] - A[1]) - (C[0] - A[0]) * (B[1] - A[1])));
        }
      }
    }

    return ans;
  }
};

int main(){
    Solution sol;
    vector<vector<int>> points = {{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}};
    cout<<"Largest Trinagle area will be : "<<sol.largestTriangleArea(points);
}
// Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles. The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2). The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2-ax1)*(ay2-ay1);
        int area2 = (bx2-bx1)*(by2-by1);
        
        int overlap = max({0, min(ax2,bx2)-max(ax1,bx1)}) * max({0, min(ay2,by2)-max(ay1,by1)});
        
        return area1+area2-overlap;
    }
};

int main(){
    Solution s;
    cout<<"Total area : "<<s.computeArea(-3,0,3,4,0,-1,9,2)<<endl;
    return 0;
}
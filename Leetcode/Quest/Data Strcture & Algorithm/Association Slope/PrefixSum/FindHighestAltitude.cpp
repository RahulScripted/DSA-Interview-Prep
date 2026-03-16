// There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0. You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, current = 0;
        for(const int alt : gain){
            current += alt;
            ans = max(ans, current);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> gain = {-5,1,5,0,-7};
    cout << "The highest altitude is: " << sol.largestAltitude(gain) << endl;
    return 0;
}
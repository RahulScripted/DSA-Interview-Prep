// You are climbing a staircase. It takes n steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int temp1 = 0, temp2 = 1;
        while(n--){
            int temp = temp1 + temp2;
            temp1 = temp2;
            temp2 = temp;
        }
        return temp2;
    }
};

int main() {
    Solution sol;
    int n = 2;
    cout << "Number of ways to climb " << n << " stairs: " << sol.climbStairs(n) << endl;

    n = 3;
    cout << "Number of ways to climb " << n << " stairs: " << sol.climbStairs(n) << endl;
    return 0;
}
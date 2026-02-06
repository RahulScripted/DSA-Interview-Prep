// Given an integer n, return the number of trailing zeroes in n!.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n){
            n /= 5;
            ans += n;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    int n = 100;
    cout << "Number of Trailing Zeroes : " << sol.trailingZeroes(n) << endl;
}
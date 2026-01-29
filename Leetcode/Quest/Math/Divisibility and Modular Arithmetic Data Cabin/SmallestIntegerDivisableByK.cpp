// Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1. Return the length of n. If there is no such n, return -1.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int remainder = 0;
        for(int i = 1;i <= k;i++){
            remainder = (remainder * 10 + 1) % k;
            if(remainder == 0) return i;
        } 
        return -1;
    }
};

int main() {
    Solution sol;
    int k = 1;
    cout << sol.smallestRepunitDivByK(k) << endl;

    k = 2;
    cout << sol.smallestRepunitDivByK(k) << endl;

    k = 3;
    cout << sol.smallestRepunitDivByK(k) << endl;
}
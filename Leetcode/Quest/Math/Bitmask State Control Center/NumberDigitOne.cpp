// Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int ans = 0;

        for (long pow10 = 1; pow10 <= n; pow10 *= 10) {
            const long divisor = pow10 * 10;
            const int quotient = n / divisor;
            const int remainder = n % divisor;
            if (quotient > 0) ans += quotient * pow10;
            if (remainder >= pow10) ans += min(remainder - pow10 + 1, pow10);
        }

        return ans;
    }
};

int main(){
    Solution sol;
    int n = 13;
    cout<<"Total number of digit 1 is : "<<sol.countDigitOne(n)<<endl;
}
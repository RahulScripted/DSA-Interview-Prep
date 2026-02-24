// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.




#include <bitss/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        for (; x; x /= 10) {
            if (ans < INT_MIN / 10 || ans > INT_MAX / 10) return 0;
            ans = ans * 10 + x % 10;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    cout << "Reverse of 123: " << sol.reverse(123) << endl;
    cout << "Reverse of -123: " << sol.reverse(-123) << endl;
    cout << "Reverse of 120: " << sol.reverse(120) << endl;
}
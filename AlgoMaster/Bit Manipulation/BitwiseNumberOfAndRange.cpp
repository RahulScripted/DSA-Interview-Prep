// Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shiftBits = 0;

        while (left != right) {
            left >>= 1;
            right >>= 1;
            ++shiftBits;
        }
        return left << shiftBits;
    }
};

int main() {
    Solution sol;
    int left = 5, right = 7;
    cout << "Bitwise AND of range [" << left << ", " << right << "] is: " << sol.rangeBitwiseAnd(left, right) << endl;
    return 0;
}
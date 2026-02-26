// Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:

//     1 - If the current number is even, you have to divide it by 2.
//     2 - If the current number is odd, you have to add 1 to it.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int steps = 0, carry = 0;
        for (int i = s.length() - 1; i > 0; i--) {
            int bit = s[i] & 1;
            steps += 1 + (bit ^ carry);
            carry |= bit;
        }
        return steps + carry;
    }
};

int main() {
    Solution sol;
    string s = "1101";
    cout << "Number of steps to reduce " << s << " to 1: " << sol.numSteps(s) << endl;
    return 0;
}
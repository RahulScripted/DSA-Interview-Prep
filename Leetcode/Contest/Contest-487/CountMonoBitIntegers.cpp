// You are given an integer n. An integer is called Monobit if all bits in its binary representation are the same. Return the count of Monobit integers in the range [0, n] (inclusive).




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMonobit(int n) {
        return bit_width((unsigned int)n + 1);
    }
};

int main() {
    Solution sol;
    int n = 8;
    cout << "The count of Monobit integers is : " << sol.countMonobit(n) << endl;
}
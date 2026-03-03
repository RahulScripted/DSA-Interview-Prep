// You are given an integer n. In one operation, you may split an integer x into two positive integers a and b such that a + b = x. The cost of this operation is a * b. Return an integer denoting the minimum total cost required to split the integer n into n ones.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n) {
       return n * (n - 1) / 2;
    }
};

int main() {
    Solution sol;
    int n = 5;
    cout << "Minimum cost to split " << n << " into ones: " << sol.minCost(n) << endl;
    return 0;
}
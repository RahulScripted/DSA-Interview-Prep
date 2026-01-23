// Given a positive integer n, find the pivot integer x such that: The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively. Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int sum = ((n * n) + n) / 2, squareRoot = sqrt(sum);
        return squareRoot * squareRoot == sum ? squareRoot : -1;
    }
};

int main() {
    Solution sol;
    int n = 8;
    cout << "Pivot Integer for " << n << " is: " << sol.pivotInteger(n) << endl;

    n = 1;
    cout << "Pivot Integer for " << n << " is: " << sol.pivotInteger(n) << endl;

    n = 4;
    cout << "Pivot Integer for " << n << " is: " << sol.pivotInteger(n) << endl;
}
// An ugly number is a positive integer which does not have a prime factor other than 2, 3, and 5. Given an integer n, return true if n is an ugly number.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if(n == 0) return false;

        for(const int prime : {2, 3, 5}){
            while(n % prime == 0) n /= prime;
        }
        return n == 1;
    }
};

int main() {
    Solution sol;
    int n = 6;
    if (sol.isUgly(n)) cout << n << " is an ugly number." << endl;
    else cout << n << " is not an ugly number." << endl;

    n = 14;
    if (sol.isUgly(n)) cout << n << " is an ugly number." << endl;
    else cout << n << " is not an ugly number." << endl;
    return 0;
}
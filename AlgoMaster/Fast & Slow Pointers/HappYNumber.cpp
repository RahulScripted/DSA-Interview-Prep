// Write an algorithm to determine if a number n is happy. A happy number is a number defined by the following process:

//     1 - Starting with any positive integer, replace the number by the sum of the squares of its digits.
//     2 - Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
//     3 - Those numbers for which this process ends in 1 are happy.

// Return true if n is a happy number, and false if not.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int slow = squaredSum(n);
        int fast = squaredSum(squaredSum(n));

        while (slow != fast) {
            slow = squaredSum(slow);
            fast = squaredSum(squaredSum(fast));
        }

        return slow == 1;
    }

private:
    int squaredSum(int n) {
        int sum = 0;
        while (n > 0) {
        sum += pow(n % 10, 2);
        n /= 10;
        }
        return sum;
    };
};

int main() {
    Solution sol;
    int n = 19;
    cout << "Is " << n << " a happy number? " << (sol.isHappy(n) ? "Yes" : "No") << endl;
    return 0;
}
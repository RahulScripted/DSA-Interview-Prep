// There is a special square room with mirrors on each of the four walls. Except for the southwest corner, there are receptors on each of the remaining corners, numbered 0, 1, and 2. The square room has walls of length p and a laser ray from the southwest corner first meets the east wall at a distance q from the 0th receptor. Given the two integers p and q, return the number of the receptor that the ray meets first.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        while(b) {
            a = a % b;
            swap(a, b);
        }
        return a;
    }

    int mirrorReflection(int p, int q) {
        int lcm = (p * q) / gcd(p, q);
        int m = lcm / p;
        int n = lcm / q;
        if(m % 2 == 0 && n % 2 == 1) return 0;
        if(m % 2 == 1 && n % 2 == 1) return 1;
        if(m % 2 == 1 && n % 2 == 0) return 2;
        return -1;
    }
};

int main() {
    Solution sol;
    int p = 3, q = 1;
    cout << "The number of the receptor that the ray meets first is: " << sol.mirrorReflection(p, q) << endl;
    return 0;
}
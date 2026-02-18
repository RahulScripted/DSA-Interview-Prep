// Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int x = n ^ (n >> 1);
        return (x & (x + 1)) == 0;
    }
};

int main(){
    Solution sol;
    int n = 5;
    if(sol.hasAlternatingBits(n)) cout<<n<<" has alternative bits";
    else cout<<n<<" has not alternative bits";
}
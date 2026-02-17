// Reverse bits of a given 32 bits signed integer.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            res <<= 1;
            res |= (n & 1);
            n >>= 1;
        }
        return res;
    }
};

int main(){
    Solution sol;
    int n = 43261596;
    cout<<"Reverse bits of "<<n<<" will be : "<<sol.reverseBits(n)<<endl;
}
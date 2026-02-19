// An n-bit gray code sequence is a sequence of 2n integers where:

//     1 - Every integer is in the inclusive range [0, 2n - 1],
//     2 - The first integer is 0,
//     3 - An integer appears no more than once in the sequence,
//     4 - The binary representation of every pair of adjacent integers differs by exactly one bit, and
//     5- The binary representation of the first and last integers differs by exactly one bit.

// Given an integer n, return any valid n-bit gray code sequence.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans{0};
        for (int i = 0; i < n; ++i){
            for (int j = ans.size() - 1; j >= 0; --j) ans.push_back(ans[j] | 1 << i);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    int n = 2;
    vector<int>ans = sol.grayCode(n);
    cout<<"Gray code sequence for number "<<n<<" is : ";
    for(auto it: ans) cout<<it<<" ";
}
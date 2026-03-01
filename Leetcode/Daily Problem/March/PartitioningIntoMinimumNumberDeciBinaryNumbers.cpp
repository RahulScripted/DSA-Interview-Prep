// Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int maxi = 0;
        for(char ch : n) maxi = max(maxi, ch - '0');
        return maxi;
    }
};

int main() {
    Solution sol;
    string n = "32";
    cout << "Minimum partitions needed: " << sol.minPartitions(n) << endl;
}
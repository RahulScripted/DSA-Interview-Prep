// Given an array a, return an array b of the same length where for each i: b[i] = a[i - 1] + a[i] + a[i + 1] If an index is out of bounds, use 0 for that term.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSumArray(vector<int>& a) {
        int n = a.size();
        vector<int> b(n, 0);
        for (int i = 0; i < n; i++) {
            int left = (i - 1 >= 0) ? a[i - 1] : 0;
            int current = a[i];
            int right = (i + 1 < n) ? a[i + 1] : 0;

            b[i] = left + current + right;
        }
        
        return b;
    }
};

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> result = getSumArray(a);
    cout << "Result array: ";
    for (int val : result) cout << val << " ";
}
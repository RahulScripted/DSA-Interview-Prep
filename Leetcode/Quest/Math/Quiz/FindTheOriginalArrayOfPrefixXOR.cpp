// You are given an integer array pref of size n. Find and return the array arr of size n that satisfies: pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i].





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
         vector<int> ans(pref.size());

        ans[0] = pref[0];
        for (int i = 1; i < ans.size(); ++i)
          ans[i] = pref[i] ^ pref[i - 1];
    
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> pref = {5, 2, 0, 3, 1};
    vector<int> result = sol.findArray(pref);
    
    cout << "Result : ";
    for (int num : result) cout << num << " ";
}
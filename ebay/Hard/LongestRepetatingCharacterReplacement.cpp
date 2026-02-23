// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times. Return the length of the longest substring containing the same letter you can get after performing the above operations.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), ans = 0, longest = 0;
        vector<int>seen(26, 0);
        for(int left = 0, right = 0;right < n; ++right){
            longest = max(longest, ++seen[s[right] - 'A']);
            if((longest + k) < (right - left + 1)) --seen[s[left++] - 'A'];
            ans = max(ans, (right - left) + 1);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    string s = "AABABBA";
    int k = 1;
    cout << "Length of longest substring: " << sol.characterReplacement(s, k) << endl; 
}
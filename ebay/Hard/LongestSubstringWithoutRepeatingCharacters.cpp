// Given a string s, find the length of the longest substring without duplicate characters.




#include <bits/stdc++.h>
using namesapce std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), left = 0, maxLen = 0;
        unordered_set<char>seen;
        for(int right = 0; right < n;right++){
            while(seen.count(s[right])){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

int main(){
    Solution sol;
    string s = "abcabcbb";
    cout<<"Longest substring without duplicate characters are : "<<sol.lengthOfLongestSubstring(s)<<endl;
}
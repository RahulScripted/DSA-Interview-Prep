// Given two strings s and t, return true if t is an anagram of s, and false otherwise.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() > t.length()) return false;
        vector<int> freq(26, 0);
        for(char ch : s) freq[ch - 'a']++;
        for(char ch : t){
            if(freq[ch - 'a'] == 0) return false;
            freq[ch - 'a']--;
        }
        return true;
    }
};
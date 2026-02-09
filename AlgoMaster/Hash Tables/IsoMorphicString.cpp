// Given two strings s and t, determine if they are isomorphic. Two strings s and t are isomorphic if the characters in s can be replaced to get t. All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapST;
        unordered_map<char, char> mapTS;

        for (int i = 0; i < s.length(); i++) {
            char sc = s[i], tc = t[i];
            if (mapST.count(sc) && mapST[sc] != tc) return false;
            if (mapTS.count(tc) && mapTS[tc] != sc) return false;

            mapST[sc] = tc;
            mapTS[tc] = sc;
        }
        return true;
    }
};
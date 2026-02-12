// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.length() < needle.length()) return -1;

        for(int i = 0;i <= (haystack.length() - needle.length()); i++){
            if(haystack.substr(i, needle.length()) == needle) return i;
        }
        return -1;
    }
};

int main(){
    Solution sol;
    cout<<sol.strStr("sadbutsad", "sad")<<endl;
    cout<<sol.strStr("leetcode", "leeto")<<endl;
}
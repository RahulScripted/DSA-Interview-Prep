// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackSize = haystack.size(), needleSize = needle.size();
        if(haystackSize < needleSize) return -1;

        for(int i = 0;i <= (haystackSize - needleSize);i++){
            if(haystack.substr(i, needleSize) == needle) return i;
        }
        return -1;
    }
};

int main(){
    Solution sol;
    string haystack = "sadbutsad", needle = "sad";
    cout << "The index of first occurrence is: " << sol.strStr(haystack, needle) << endl;
    return 0;
}
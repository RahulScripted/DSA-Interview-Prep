// Given a string s consisting of words and spaces, return the length of the last word in the string.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.size() - 1;
        while(end >= 0 && s[end] == ' ') end--;

        int start = end;
        while(start >= 0 && s[start] != ' ') start--;

        return end - start;
    }
};

int main(){
    Solution sol;
    string s = "Hello World";
    cout<<"Length of last word is : "<<sol.lengthOfLastWord(word);
}
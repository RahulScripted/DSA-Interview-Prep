// Given an input string s, reverse the order of the words. A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space. Return a string of the words in reverse order concatenated by a single space.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        while (ss >> word) words.push_back(word);

        string res;
        for (int i = words.size() - 1; i >= 0; i--) {
            res += words[i];
            if (i != 0) res += " ";
        }

        return res;
    }
};

int main(){
    Solution sol;
    string s = "   hello world";
    cout<<"Reverse of "<<s<<" will be : "<<sol.reverseWords(s);
}
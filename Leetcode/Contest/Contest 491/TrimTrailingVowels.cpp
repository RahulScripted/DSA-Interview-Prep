// You are given a string s that consists of lowercase English letters. Return the string obtained by removing all trailing vowels from s.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string trimTrailingVowels(string s) {
        int n = s.length();
        while(s[n-1] == 'a' | s[n-1] == 'e'| s[n-1] == 'i' | s[n-1] == 'o' | s[n-1] == 'u'){
            s.pop_back();
            n--;
            if(n==0) break;
        }
        return s;
    }
};

int main(){
    Solution s;
    cout << "After trimming trailing vowels: " <<s.trimTrailingVowels("leetcode");
}
// You are given a string s consisting of lowercase English letters, spaces, and digits. Let v be the number of vowels in s and c be the number of consonants in s. A vowel is one of the letters 'a', 'e', 'i', 'o', or 'u', while any other letter in the English alphabet is considered a consonant. The score of the string s is defined as follows: If c > 0, the score = floor(v / c) where floor denotes rounding down to the nearest integer. Otherwise, the score = 0. Return an integer denoting the score of the string.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int vowelConsonantScore(string s) {
        int countVowel = 0, countConsonant = 0;
        int n = s.length();
        for(int i = 0;i < n;i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') countVowel++;
            else if(int(s[i]) >= 97 && int(s[i]) <= 122) countConsonant++;
        }
        return countConsonant == 0 ? 0 : floor(countVowel) / floor(countConsonant);
    }
};

int main() {
    Solution sol;
    string s = "aeiou bcdfg";
    cout << sol.vowelConsonantScore(s) << endl;
    s = "cooear";
    cout << sol.vowelConsonantScore(s) << endl;
    s = "i3";
    cout << sol.vowelConsonantScore(s) << endl;
    return 0;
}
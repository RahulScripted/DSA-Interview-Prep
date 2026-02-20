// // You are given a personal information string s, representing either an email address or a phone number. Return the masked personal information using the below rules.

// Email address:
// 1 - A name consisting of uppercase and lowercase English letters, followed by
// 2 - The '@' symbol, followed by
// 3 - The domain consisting of uppercase and lowercase English letters with a dot '.' somewhere in the middle (not the first or last character).

// To mask an email:
// 1 - The uppercase letters in the name and domain must be converted to lowercase letters.
// 2 - The middle letters of the name (i.e., all but the first and last letters) must be replaced by 5 asterisks "*****".

// Phone number:
// 1 - The phone number contains 10-13 digits.
// 2 - The last 10 digits make up the local number.
// 3 - The remaining 0-3 digits, in the beginning, make up the country code.
// 4 - Separation characters from the set {'+', '-', '(', ')', ' '} separate the above digits in some way.
// To mask a phone number:

// Remove all separation characters.
// 1 - The masked phone number should have the form:
// 2 - "***-***-XXXX" if the country code has 0 digits.
// 3 - "+*-***-***-XXXX" if the country code has 1 digit.
// 4 - "+**-***-***-XXXX" if the country code has 2 digits.
// 5 - "+***-***-***-XXXX" if the country code has 3 digits.
// 6 - "XXXX" is the last 4 digits of the local number.







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maskPII(string s) {
        if (auto at = s.find('@'); at != string::npos) {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            return s.front() + string("*****") + s.substr(at - 1);
        }

        string digits;
        for (char c : s){
            if (isdigit(c)) digits += c;
        }

        int n = digits.size();
        string local = "***-***-" + digits.substr(n - 4);

        if (n == 10) return local;
        return "+" + string(n - 10, '*') + "-" + local;
    }
};

int main(){
    Solution sol;
    string s = "LeetCode@LeetCode.com";
    cout<<"After masking : "<<sol.maskPII(s);
}
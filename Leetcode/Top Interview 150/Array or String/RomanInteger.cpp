// Given a roman numeral, convert it to an integer.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int n = s.size() - 1,result = 0;
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10}, 
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        for(int i = 0;i < n;i++){
            if(roman[s[i]] < roman[s[i + 1]]) result -= roman[s[i]];
            else result += roman[s[i]];
        }

        return result + roman[s[n]];
    }
};

int main(){
    Solution sol;
    string s = "MCMXC";
    cout<<"In number it will be : "<<sol.romanToInt(s);
}
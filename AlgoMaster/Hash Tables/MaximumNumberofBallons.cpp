// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible. You can use each character in text at most once. Return the maximum number of instances that can be formed.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>freq(26, 0);
        for(char ch : text) freq[ch - 'a']++;
        
        int b = freq['b' - 'a'];
        int a = freq['a' - 'a'];
        int l = freq['l' - 'a'] / 2;
        int o = freq['o' - 'a'] / 2;
        int n = freq['n' - 'a'];

        return min({b, a, l, o, n});
    }
};

int main() {
    Solution sol;
    text = "nlaebolko";
    cout<<"Maximum number of instances will be : "<<sol.maxNumberOfBalloons(text);
}
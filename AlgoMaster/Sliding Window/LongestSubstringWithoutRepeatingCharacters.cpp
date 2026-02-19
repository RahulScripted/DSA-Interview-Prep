// Given a string s, find the length of the longest substring without duplicate characters.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            while (st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main(){
    Solution sol;
    string s = "abcabcbb";
    cout<<"Length of the longest substring : "<<sol.lengthOfLongestSubstring(s)<<endl;
}
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for(string& str : strs){
            vector<int>count(26,0);
            for(char ch : str) count[ch - 'a']++;
            string key;
            for(int num : count) key += to_string(num) + "#";
            mp[key].push_back(str);
        }

        vector<vector<string>> result;
        for(auto& entry : mp) result.push_back(move(entry.second));
        return result;
    }
};

int main(){
    Solution s;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = s.groupAnagrams(strs);
    for(vector<string> vec : result){
        for(string str : vec) cout << str << " ";
        cout << endl;
    }
    return 0;
}
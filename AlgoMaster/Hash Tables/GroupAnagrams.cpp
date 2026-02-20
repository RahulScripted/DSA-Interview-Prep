// Given an array of strings strs, group the anagrams together. You can return the answer in any order.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;

        for(string& str : strs){
            vector<int>count(26, 0);
            for(char ch : str) count[ch - 'a']++;
            string key;
            for(int num : count) key += to_string(num) + "#";
            ans[key].push_back(str);
        }

        vector<vector<string>>result;
        for(auto& entry : ans) result.push_back(move(entry.second));
        return result;
    }
};

int main(){
    Solution sol;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = sol.groupAnagrams(strs);
    cout<<"Anagrams are as  follows : "<<endl;
    for(int i=0;i<result.size();i++){
        for(int j=0;j(result[i].size());j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
}
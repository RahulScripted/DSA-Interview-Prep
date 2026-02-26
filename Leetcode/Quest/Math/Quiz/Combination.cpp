// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        dfs(n, k, 1, {}, ans);
        return ans;
    }

private:
    void dfs(int n, int k, int s, vector<int>&& path, vector<vector<int>>& ans) {
        if (path.size() == k) {
        ans.push_back(path);
        return;
        }

        for (int i = s; i <= n; ++i) {
        path.push_back(i);
        dfs(n, k, i + 1, std::move(path), ans);
        path.pop_back();
        }
    }
};

int main() {
    Solution sol;
    int n = 4, k = 2;
    vector<vector<int>> ans = sol.combine(n, k);
    cout<<"All  combinations are : "<<endl;
    for (const auto& v : ans) {
        for (int x : v) cout << x << " ";
        cout << endl;
    }
}
// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).





#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root -> left), levels(root -> right));
    }

    void nthLevel(TreeNode* root, int current, int level, vector<int>& v){
        if(root == NULL) return;
        if(current == level){
            v.push_back(root -> val);
            return;
        }
        nthLevel(root -> left, current + 1, level, v);
        nthLevel(root -> right, current + 1, level, v);
    }
    
    void lOrder(TreeNode* root, vector<vector<int>>& ans){
        int n = levels(root);
        for(int i = 0;i < n;i++){
            vector<int> v;
            nthLevel(root,0, i, v);
            ans.push_back(v);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        lOrder(root, ans);
        return ans;
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    root -> left = new TreeNode(9);
    root -> right = new TreeNode(20);
    root -> right -> left = new TreeNode(15);
    root -> right -> right = new TreeNode(7);

    Solution s;
    vector<vector<int>> ans = s.levelOrder(root);
    cout<<"Level order traversal of the binary tree is: " << endl;
    for(auto i : ans){
        for(auto j : i) cout << j << " ";
        cout << endl;
    }
}
// You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit. For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.




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
    int DFS(TreeNode* rt, int x) {
        if (rt == nullptr) return 0;
        x = x * 2 + rt->val;
        if (rt->left == rt->right) return x;
        return DFS(rt->left, x) + DFS(rt->right, x);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        return DFS(root, 0);
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    
    cout << "Sum of root to leaf binary numbers: " << sol.sumRootToLeaf(root) << endl;
    return 0;
}
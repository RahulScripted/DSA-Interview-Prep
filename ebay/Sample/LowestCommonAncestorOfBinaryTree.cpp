// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree. According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”





#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        TreeNode* leftDirection = lowestCommonAncestor(root -> left, p, q);
        TreeNode* rightDirection = lowestCommonAncestor(root -> right, p, q);
        if(leftDirection && rightDirection) return root;
        return leftDirection ? leftDirection : rightDirection;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    root -> right -> left = new TreeNode(6);
    root -> right -> right = new TreeNode(7);

    Solution sol;
    TreeNode* p = root -> left;
    TreeNode* q = root -> right;
    cout << "Lowest Common Ancestor of " << p -> val << " and " << q -> val << " is: " << sol.lowestCommonAncestor(root, p, q) -> val << endl;
    
    p = root -> left -> left;
    q = root -> right;
    cout << "Lowest Common Ancestor of " << p -> val << " and " << q -> val << " is: " << sol.lowestCommonAncestor(root, p, q) -> val << endl;
}
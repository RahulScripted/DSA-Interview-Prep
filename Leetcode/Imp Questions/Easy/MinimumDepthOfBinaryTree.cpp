// Given a binary tree, find its minimum depth. The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.




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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int leftPart = minDepth(root -> left);
        int rightPart = minDepth(root -> right);
        if(leftPart == 0 || rightPart == 0) return 1 + max(leftPart, rightPart);
        return 1 + min(leftPart, rightPart);
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "The minimum depth of the binary tree is: " << sol.minDepth(root) << endl;
}
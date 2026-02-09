// Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them. A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.




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
    void inorder(TreeNode* node, vector<int>&vals){
        if(!node) return;
        inorder(node -> left, vals);
        vals.push_back(node -> val);
        inorder(node -> right, vals);
    }

    TreeNode* buildTree(const vector<int>&vals, int left, int right){
        if(left > right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(vals[mid]);
        node -> left = buildTree(vals, left, mid - 1);
        node -> right = buildTree(vals, mid + 1, right);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>vals;
        inorder(root, vals);
        int n = vals.size() - 1;
        return buildTree(vals, 0, n);
    }
};

void printInOrder(TreeNode* node) {
    if (!node) return;
    printInOrder(node->left);
    cout << node->val << " ";
    printInOrder(node->right);
}

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);  
    cout << "Before Balanced BST : ";
    printInOrder(root);
    cout<<endl;
    
    TreeNode* balancedRoot = sol.balanceBST(root);    
    cout << "After Balanced BST : ";
    printInOrder(balancedRoot);
}
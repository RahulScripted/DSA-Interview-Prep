// Given the root of a binary tree, invert the tree, and return its root.




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
    void swap(TreeNode* &left, TreeNode* &right){
        TreeNode* temp = left;
        left = right;
        right = temp;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        if(!root -> left && !root -> right) return root;
        invertTree(root -> left);
        invertTree(root -> right);
        swap(root -> left, root -> right);
        return root;
    }
};

void print(TreeNode* root){
    if(!root) return;
    cout<< root -> val << " ";
    print(root -> left);
    print(root -> right);
}

int main(){
    Solution sol;
    TreeNode* root = new TreeNode(4);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(7);
    root -> left -> left = new TreeNode(1);
    root -> left -> right = new TreeNode(3);
    root -> right -> left = new TreeNode(6);
    root -> right -> right = new TreeNode(9);
    cout<< "Original Tree: ";
    print(root);
    sol.invertTree(root);
    cout<< "Inverted Tree: ";
    print(root);
}
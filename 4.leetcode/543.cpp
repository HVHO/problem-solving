// 543. Diameter of Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: 
    int maxWidth(TreeNode* root, int& res) {
        if(!root) return 0;
        int l = maxWidth(root->left, res);
        int r = maxWidth(root->right, res);
        res = max(res, l + r);
        return max(l,r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        maxWidth(root, res);
        return res;
    }
};

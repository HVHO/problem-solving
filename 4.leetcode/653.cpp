// 653. Two Sum IV - Input is a BST

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
    bool dfs(TreeNode* root, int k, TreeNode* cur) {
        if(!root || root == cur) return false;
        if(root->val == k) return true;
        return dfs(root->left,k, cur) || dfs(root->right,k, cur);
        
    }
    
    bool dfs1(TreeNode* cur, int k, TreeNode* root) {
        if(!cur) return false;
        
        if(dfs(root, k - cur -> val, cur)) return true;
        return dfs1(cur->left, k, root) || dfs1(cur->right,k,root);
    }
    
    bool findTarget(TreeNode* root, int k) {
        return dfs1(root, k, root);
    }
};

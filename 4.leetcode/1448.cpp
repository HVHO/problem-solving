// 1448. Count Good Nodes in Binary Tree

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
    
    int dfs(TreeNode* root, int max) {
        if(!root) return 0;
        
        int res = 0;
        if(root -> val >= max) {
            res++;
            max = root->val;
        } 
        res += dfs(root->left, max);
        res += dfs(root->right, max);
        return res;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, -10001);
    }
};

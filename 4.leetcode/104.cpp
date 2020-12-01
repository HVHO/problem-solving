// 104.	Maximum Depth of Binary Tree    
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
    
    int dfs(TreeNode* root, int dep) {
        if(!root) return dep;
        return max(dfs(root->left, dep + 1),dfs(root->right, dep + 1));
        
    }
    int maxDepth(TreeNode* root) {
        return dfs(root,0);
        
    }
};
// 98. Validate Binary Search Tree   

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
    
    bool dfs(TreeNode* root, long long min, long long max) {
        
        if(!root) return true;
        if(root->val < min || root->val > max) return false;
        
        if(!dfs(root->left, min, (long long)root->val - 1)) return false;
        if(!dfs(root->right, (long long)root->val + 1, max)) return false;
        
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        return dfs(root,INT_MIN , INT_MAX);
    }
};

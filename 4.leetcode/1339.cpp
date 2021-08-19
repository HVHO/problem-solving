// 1339. Maximum Product of Splitted Binary Tree

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
    
    int getSum(TreeNode* root) {
        if(!root) return 0;
        return getSum(root->left) + getSum(root->right) + root->val;
    }
    
    int dfs(TreeNode* root, int sum, long long &max) {
        if(!root) return 0;
        
        int l = dfs(root->left, sum, max);
        int r = dfs(root->right, sum, max);
        
        int s = l + r + root -> val;
        long long t = (long long) s * (sum - s);
        if(max < t) max = t;
        
        return s;
    }
    
    int maxProduct(TreeNode* root) {
        int s = getSum(root);
        
        long long m = 0;
        dfs(root, s, m);
        return (int)(m%1000000007ll);
        
    }
};

// 1022.	Sum of Root To Leaf Binary Numbers    

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
    
    void dfs(TreeNode* root, int path, int &sum) {
        
        if(!root->left && !root->right){
            sum += 2*path + root->val;
            return;
        }
        
        if(root->left) dfs(root -> left, 2*path + root->val, sum);
        if(root->right) dfs(root -> right, 2*path + root->val, sum);
        
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        
        dfs(root, 0, res);
        
        return res;
        
    }
};
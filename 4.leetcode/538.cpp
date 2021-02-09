// 538. Convert BST to Greater Tree   

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
    // post order travel
    void dfs(TreeNode* root, int &bias) {
        if(!root) return;
        dfs(root->right, bias);
        bias+= root->val;
        root->val = bias;
        dfs(root->left, bias);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int bias = 0;
        dfs(root, bias);
        return root;
    }
};

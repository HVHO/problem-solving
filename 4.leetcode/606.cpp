// 606. Construct String from Binary Tree

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
    string dfs(TreeNode* n) {
        if(n == nullptr) return "";
        string res = to_string(n->val);
        if(n->left == nullptr) {
            if(n->right != nullptr) res += "()";
        } else 
            res += "(" + dfs(n -> left) + ")";
        
        if(n->right != nullptr) res += "(" + dfs(n -> right) + ")";
        
        return res;
    }
    
    string tree2str(TreeNode* root) {
        return dfs(root);
    }
};

// 814. Binary Tree Pruning

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
    bool dfs(TreeNode* node) {
        // terminal case
        if(node == nullptr) 
            return false;
        
        bool lb = dfs(node -> left);
        bool rb = dfs(node -> right);
        
        if(!lb) node -> left = nullptr;
        if(!rb) node -> right = nullptr;
        
        return lb || rb || (node -> val == 1);
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        TreeNode* result = new TreeNode();
        result -> left = root;
        dfs(result);
        return result -> left;
    }
};

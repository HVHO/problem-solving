// 563. Binary Tree Tilt 

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
    
    pair<int,int> dfs(TreeNode* root) {
        if(!root) return {0,0};
        auto l = dfs(root -> left);
        auto r = dfs(root -> right);
        
        return {abs(l.second-r.second)+l.first+r.first, l.second + r.second + root -> val};
    }
    
    int findTilt(TreeNode* root) {
        return dfs(root).first;
    }
};

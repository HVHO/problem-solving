//111.	Minimum Depth of Binary Tree    
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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<pair<TreeNode*,int>> q;
        
        q.push(make_pair(root,1));
        
        while(!q.empty()) {
            TreeNode* cn = q.front().first;
            int cd = q.front().second;
            q.pop();
            
            if(cn -> left == nullptr && cn -> right == nullptr) return cd;
            if(cn -> left) q.push(make_pair(cn -> left, cd + 1));
            if(cn -> right) q.push(make_pair(cn -> right, cd + 1));
        };
        
        return -1;
    }
};
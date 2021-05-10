// 102. Binary Tree Level Order Traversal    

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        
        vector<vector<int>> res;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root, 0));
        int max_dep = 0;
        
        while(!q.empty()) {
            
            auto [node , depth] = q.front();
            q.pop();
            
            if(!node) continue;
            
            if(res.size() < (depth+1))
                res.push_back(vector<int>());
            
            res[depth].push_back(node->val);
            
            q.push(make_pair(node->left,depth+1));
            q.push(make_pair(node->right,depth+1));
            
        }
        
        return res;
    }
};

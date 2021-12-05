// 337. House Robber III


class Solution {
public:
    int rob(TreeNode* root) {
        auto res = dfs(root);
        return  res[0] > res[1] ? res[0]:res[1];
    }
    
    vector<int> dfs(TreeNode* root) {
        vector<int> res(2,0);
        if(!root) return res;
        
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        res[0] = max(left[1],left[0]) + max(right[1],right[0]);
        res[1] = left[0] + right[0] + root->val;
        
        return res;
    }
};

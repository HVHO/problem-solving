// 113. Path Sum II

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
    void dfs(TreeNode* root, vector<int> path, int remainSum, vector<vector<int>> &res) {
        if(root == nullptr) return;
        path.push_back(root -> val);
        remainSum -= root -> val;
        if(remainSum == 0 && ! root-> left && ! root -> right) {
            res.push_back(path);
            return;
        }
        dfs(root-> left, path, remainSum, res);
        dfs(root-> right, path, remainSum, res);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        dfs(root, vector<int> (), targetSum, res);
        return res;
    }
};

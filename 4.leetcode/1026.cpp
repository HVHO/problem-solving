// 1026. Maximum Difference Between Node and Ancestor


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
    
    int dfs(TreeNode* cur, int _max, int _min) {
        if(!cur) {
            return _max - _min;     
        }
        
        if(_max == -1)
            _max = _min = cur -> val;
        
        if(_max < cur -> val) _max = cur -> val;
        if(_min > cur -> val) _min = cur -> val;
        
        return max(dfs(cur->left,_max,_min),dfs(cur->right,_max,_min));
    }
    
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, -1,-1);
    }
};

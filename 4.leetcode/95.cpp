// 95. Unique Binary Search Trees II

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

    vector<TreeNode*> generateTrees(int n) {
        return dfs(1,n);
    }
    
    vector<TreeNode*> dfs(int st, int ed) {
        vector<TreeNode*> res;
        if(st > ed) {
            res.push_back(NULL);
        } else if(st == ed) {
            res.push_back(new TreeNode(st));
        } else {
            for(int i = st; i <= ed; i++) {
                vector<TreeNode*> ls = dfs(st, i - 1);
                vector<TreeNode*> rs = dfs(i + 1, ed);
                for(auto l: ls) {
                    for(auto r: rs) {
                        TreeNode* root = new TreeNode(i, l, r);
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
        
    }
};

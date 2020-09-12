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
#include<stack>

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        stack<TreeNode*> pl,ql;
        
        pl.push(p);
        ql.push(q);
        
        while(!pl.empty()) {
            p = pl.top();
            q = ql.top();
            pl.pop();
            ql.pop();
            
            if(!p && !q) continue;
            if(!p || !q) return false;
            if(p->val ^ q->val) return false;
            pl.push(p->left);
            pl.push(p->right);
            ql.push(q->left);
            ql.push(q->right);
            
        }
        
        return true;

        
    }
};
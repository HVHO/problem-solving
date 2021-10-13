// 1008. Construct Binary Search Tree from Preorder Traversal

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
    
    TreeNode* build(int idx, int rbound, vector<int>& preorder) {
        if(idx >= rbound) return nullptr;
        TreeNode* root = new TreeNode(preorder[idx]);
        
        int bound;
        for(bound = idx + 1; bound < rbound; bound++) {
            if(preorder[bound] > preorder[idx]) break;
        }
        root -> left = build(idx + 1, bound, preorder);
        root -> right = build(bound, rbound, preorder);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(0,preorder.size(),preorder);
    }
};

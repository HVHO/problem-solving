// 993. Cousins in Binary Tree

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
    int depth(TreeNode* root, int x, int dep) {
        if(!root) return -1;
        if(root->val == x) return dep;
        int l = depth(root->left, x, dep + 1);
        int r = depth(root->right, x, dep + 1);
        if(l != -1) return l;
        if(r != -1) return r;
        return -1;
    }
    
    int parent(TreeNode* root, int x) {
        if(!root) return 0;
        if(root->left&&root->left->val == x) return root->val;
        if(root->right&&root->right->val == x) return root->val;
        int l = parent(root->left, x);
        int r = parent(root->right, x);
        if(l) return l;
        if(r) return r;
        return 0;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        int xd = depth(root, x, 0);
        int yd = depth(root, y, 0);
        int xp = parent(root, x);
        int yp = parent(root, y);
        
        if(xd == yd && xp != yp) return true;
        return false;
    }
};

// 897.	Increasing Order Search Tree    
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
    TreeNode *head, *tail;
    void dfs(TreeNode* root) {
        if(root == nullptr) return;
        dfs(root->left);
        TreeNode* tmp = new TreeNode(root -> val);
        tail -> right = tmp;
        tail = tail -> right;
        dfs(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        
        head = new TreeNode();
        tail = head;
        dfs(root);
        return head -> right;
    }
};
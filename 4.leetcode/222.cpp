// 222. Count Complete Tree Nodes

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
    
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()) {
            int size = q.size();
            res += size;
            for(int i = 0; i < size; i++) {
                auto tn = q.front();
                q.pop();
                if(tn->left) q.[?12;4$ypush(tn->left);
                if(tn->right) q.push(tn->right);
            }
        }
        
        return res;
    }
};

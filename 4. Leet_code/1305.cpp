// 1305. All Elements in Two Binary Search Trees    

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

#include <algorithm>

class Solution {
public:

    void getSorted(TreeNode *root, vector<int> &a ) {
        
        if(!root) return;
        
        if(root -> left) getSorted(root->left, a);
        a.push_back(root->val);
        if(root -> right) getSorted(root->right, a);
        
        
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> a,b;
        getSorted(root1, a);
        getSorted(root2, b);
        
        int sizea, sizeb;
        sizea = a.size();
        sizeb = b.size();
        printf("%d%d",sizea,sizeb);
        
        int idxa = 0, idxb = 0;
        
        vector<int> res;
        while(idxa < sizea || idxb < sizeb) {
            
            if(idxa < sizea && idxb < sizeb) {
                if(a[idxa] < b[idxb]) {
                    res.push_back(a[idxa]);
                    idxa++;
                } else {
                    res.push_back(b[idxb]);
                    idxb++;
                }
            } else if(idxa < sizea) {
                res.push_back(a[idxa]);
                idxa++;
            } else {
                res.push_back(b[idxb]);
                idxb++;
            }
            

        }
        return res;        
    }
};
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
    static int min_diff;
    
    int getMinimumDifference(TreeNode* root) {
        min_diff = INT_MAX;
        getMinMax(root);
        return min_diff;
    }
    
    pair<int,int> getMinMax(TreeNode* root) {
        int min = root->val;
        int max = root->val;
        int left_max = root->val;
        int right_min = root->val;
        
        if(root -> left) {
            auto res = getMinMax(root->left);
            min = res.first;
            left_max = res.second;
        }
        
        if(root -> right) {
            auto res = getMinMax(root->right);
            max = res.second;
            right_min = res.first;
        }
        
        if(root->val != left_max && min_diff > abs(root->val - left_max)) min_diff = abs(root->val - left_max);
        if(root->val != right_min && min_diff > abs(right_min - root->val)) min_diff = abs(right_min - root->val);
        
        return pair<int,int>(min,max);
        
    }
};

int Solution::min_diff = INT_MAX;
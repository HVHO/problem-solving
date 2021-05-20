// 108. Convert Sorted Array to Binary Search Tree



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
    
    TreeNode* atob(vector<int>&nums, int l, int r) {
        if(l>r) return nullptr;
        int m = (l+r)/2;
        TreeNode* root = new TreeNode(nums[m]);
        root -> left = atob(nums,l, m-1);
        root -> right = atob(nums,m+1,r);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return atob(nums, 0, nums.size() - 1);
    }
};

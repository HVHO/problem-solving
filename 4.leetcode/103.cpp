// 103.Binary Tree Zigzag Level Order Traversal

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


#include <vector>
#include <algorithm>

class Solution
{
public:
    vector<vector<int>> zigzag;

    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        zigzag.clear();
        dfs(root, 0);

        bool flag = false;
        for (int i = 0; i < zigzag.size(); i++)
        {
            if (flag)
            {
                reverse(zigzag[i].begin(), zigzag[i].end());
            }
            flag = !flag;
        }

        return zigzag;
    }

    void dfs(TreeNode *root, int level)
    {

        if (!root)
            return;

        if (zigzag.size() < level + 1)
        {
            vector<int> v;
            zigzag.push_back(v);
        }
        zigzag[level].push_back(root->val);

        if (root->left)
        {
            dfs(root->left, level + 1);
        }
        if (root->right)
        {
            dfs(root->right, level + 1);
        }
        return;
    }
};
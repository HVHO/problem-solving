// 106. Construct Binary Tree from Inorder and Postorder Traversal

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return dfs({0,n-1},{0,n-1},inorder,postorder);
    }
    
    TreeNode* dfs(pair<int,int> pi, pair<int,int> pp, vector<int>& vi, vector<int>& vp)     {
        // printf("%d %d | %d %d\n",pi.first,pi.second,pp.first,pp.second);
        
        if(pi.first > pi.second) return nullptr;
        if(pi.first == pi.second) return new TreeNode(vi[pi.first]);
        
        int root = vp[pp.second];
        int midx;
        for(midx = pi.first; midx <= pi.second; midx++) {
            if(vi[midx] == root) break;
        }
        
        int lidx = pp.first, ridx = pp.first;
        for(int i = pp.second-1; i >= pp.first; i--) {
            bool flag = false;
            for(int j = midx+1; j <= pi.second; j++)
                if(vi[j] == vp[i]) {
                    flag = true;
                    break;
                }
            if(!flag) {
                ridx = i + 1;
                break;
            }
        }
        
        auto l = dfs({pi.first, midx - 1},{lidx, ridx - 1},vi,vp);
        auto r = dfs({midx + 1, pi.second},{ridx, pp.second - 1},vi,vp);
        return new TreeNode(root, l,r);
    }
};

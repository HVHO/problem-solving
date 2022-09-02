// 637. Average of Levels in Binary Tree

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<long long>> v;
        
        queue<pair<int, TreeNode*>> q;
        q.push({0,root});
        
        while(!q.empty()) {
            auto [dep, n] = q.front();
            q.pop();
            if(n == nullptr) continue;
            if(v.size() <= dep) v.push_back(vector<long long>());
            v[dep].push_back(n->val);
            q.push({dep+1,n -> left});
            q.push({dep+1,n -> right});
        }
        
        vector<double> res(v.size(),0.0);
        for(int i = 0; i < v.size(); i++) {
            long long sum = 0;
            for(int j = 0; j < v[i].size(); j++)
                sum += v[i][j];
            res[i] = (double)sum / v[i].size();
                
        }
        
        return res;
    }
};

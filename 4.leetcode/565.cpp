// 565. Array Nesting

class Solution {
public:
    void dfs(int idx, int depth, int &res, vector<int> &n, vector<int> &v) {
        
        if(v[idx] != -1) return;
        
        v[idx] = depth;
        int next = n[idx];
        if(v[next] != -1) {
            if((depth - v[next] + 1 ) > res) res = (depth - v[next]  + 1);
        } else {
            dfs(next, depth + 1, res, n , v);
        }
        
        return;
    }
    
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, -1);
        int res = 0;
        
        for(int i = 0; i < n; i++) {
            dfs(i, 0, res, nums, v);
        }
        
        return res;
    }
};

// 834. Sum of Distances in Tree


class Solution {
public:
    int N;
    vector<int> cnt;
    vector<int> res;
    vector<unordered_set<int>> tree;
    
    void dfs1(int idx, int pre) {
        for(auto n: tree[idx]) {
            if(n == pre) continue;
            res[n] = res[idx] - cnt[n] + N - cnt[n];
            dfs1(n, idx);
        }
        
        return;
    }
    
    void dfs(int idx, int pre) {
        
        for(auto n: tree[idx]) {
            if(n == pre) continue;
            dfs(n, idx);
            cnt[idx] += cnt[n];
            res[idx] += res[n] + cnt[n];
        } 
        
        return;
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        res = vector<int>(n,0);
        cnt = vector<int>(n,1);
        tree.resize(n);
        
        for(auto v: edges) {
            tree[v[0]].insert(v[1]);
            tree[v[1]].insert(v[0]);
        }
        
        dfs(0, -1);
        dfs1(0, -1);
        
        return res;
    }
};

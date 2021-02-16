// 1337. The K Weakest Rows in a Matrix    

class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b) {
        if(a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> v;
        for(int i = 0; i < mat.size(); i++) {
            int count = 0;
            for(auto e: mat[i]) {
                if(e == 1) count++;
            }
            v.push_back(pair(count, i));
        }
        
        sort(v.begin(), v.end(), cmp);
        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.push_back(v[i].second);
        }
        return res;
    }
};

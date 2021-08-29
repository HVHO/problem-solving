// 1235. Maximum Profit in Job Scheduling

class Solution {
public:
    int res = 0;
    
    int mem[50001] = {-1,}; // max profit when starting i'th index schedule
    
    int dfs(vector<pair<pair<int,int>,int>>& v, int st) {
        if(st == v.size()) return 0;
        if(mem[st] != -1) return mem[st];
        
        // find next start index by lower bound binary search
        int next = v[st].first.second;
        
        int l = st + 1;
        int r = v.size();
        while(l < r) {
            int m = (l + r) / 2;
            if(next <= v[m].first.first) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        
        int maxProfit = dfs(v, st + 1);
        if(maxProfit < (dfs(v, r) + v[st].second)) maxProfit = dfs(v, r) + v[st].second;
        
        return mem[st] = maxProfit;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // init
        int n = startTime.size();
        vector<pair<pair<int,int>,int>> v;
        for(int i = 0; i < 50001; i++)
            mem[i] = -1;
        for(int i = 0; i < n; i++) {
            v.push_back({{startTime[i], endTime[i]},profit[i]});
        }
        
        sort(v.begin(), v.end());
        
        return dfs(v,0);
    }
};

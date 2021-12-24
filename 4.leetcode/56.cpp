// 56. Merge Intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n<2) return intervals;
        
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> res;
        
        int rs=-1,re=-1;
        for(int i = 0; i < n; i++) {
    
            int s = intervals[i][0];
            int e = intervals[i][1];
            
            if(rs == -1) {
                rs = s,re = e;
            } else if (re < s) {
                res.push_back({rs,re});
                rs = s,re = e;
            } else {
                re = max(re,e);
            }
        }
        res.push_back({rs,re});
        
        return res;
    }
};

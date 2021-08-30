// 598. Range Addition II

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        
        if(!ops.size()) return m*n;
        
        int c = ops[0][0];
        int r = ops[0][1];
        
        for(auto &op: ops) {
            if(c > op[0])
                c = op[0];
            if(r > op[1])
                r = op[1];
        }
        
        return c*r;
    }
};

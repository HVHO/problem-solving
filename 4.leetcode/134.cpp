// 134. Gas Station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
    
        int tot = 0;
        int cur = 0;
        int res = 0;
        for(int i = 0; i < n; i++) {
            tot += gas[i] - cost[i];
            cur += gas[i] - cost[i];
            if(cur < 0) { cur = 0, res = i + 1;}
        }
        
        if(tot < 0) res = -1;
        return res;
    }
};

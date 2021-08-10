// 926. Flip String to Monotone Increasing


class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        
        int ocnts[n];
        int zcnts[n];
        
        memset(ocnts, 0, n*sizeof(int));
        memset(zcnts, 0, n*sizeof(int));
        
        int ocnt = 0;
        int zcnt = 0;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') zcnt++;
            else ocnt++;
            ocnts[i] = ocnt;
            zcnts[i] = zcnt;
        }
        
        int res = 100000;
        
        for(int i = 0; i < n - 1; i++) { // 0011 form
            int tmp = ocnts[i] + zcnts[n-1] - zcnts[i];
            if(res > tmp) res = tmp;
        }
    
        
        res = min(res, zcnts[n-1]); // 1111 form
        res = min(res, ocnts[n-1]); // 0000 form
        
        
        return res;
        
    }
};

// 1446. Consecutive Characters

class Solution {
public:
    int maxPower(string s) {
        int res = 1;
        int cnt = 1;
        char prev = 'A';
        for(auto c: s) {
            if(c==prev){
                res = max(res,++cnt);
            } else {
                cnt = 1;
                prev = c;
            }
        }
        return res;
    }
};

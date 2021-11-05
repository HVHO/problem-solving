// 441. Arranging Coins

class Solution {
public:
    int arrangeCoins(int n) {
        long long res = 0;
        long long sum = 0;
        while(true) {
            res ++;
            if((sum + res) <= n ) sum += res;
            else {res--; break;}
        }
        return res;
    }
};

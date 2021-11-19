// 461. Hamming Distance
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        for(int i = 0; i < 32; i++) {
            res += (x^y)&(1<<i) ? 1:0;
        }
        return res;
    }
};

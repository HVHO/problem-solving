// 201. Bitwise AND of Numbers Range

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int dep = 0;
        while(m != n) 
        {
            ++dep;
            m >>= 1;
            n >>= 1;
        }
        return m << dep;
    }
};

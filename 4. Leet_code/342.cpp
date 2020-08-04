// 342. Power of Four    

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num&0xaaaaaaaa) return false;
        unsigned int i = num;
        i = i - ((i >> 1) & 0x55555555);
        i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
        return ((((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24) == 1u;
    }
};
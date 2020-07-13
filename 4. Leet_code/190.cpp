class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t idx = 1;
        uint32_t ridx = 1u<<31;
        uint32_t res = 0;
        
        for(int i=0; i<32; i++) {
            if(n&(idx)) res = res|(ridx);
            idx<<=1;
            ridx>>=1;
        }
        
        return res;
    }
};
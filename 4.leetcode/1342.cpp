// 1342. Number of Steps to Reduce a Number to Zero    

class Solution {
public:
    int numberOfSteps (int num) {
        int res = 0;
        if(!num) return 0;
        
        int max_idx = 32;
        for(int i = 31; i >= 0 ; i--) {
            int mask = 0x1 << i;
            if(mask & num) {
                max_idx = i + 1;
                break;
            }
        }

        
        for(int i = 0; i < max_idx ; i++) {
            int mask = 0x1 << i;
            if(mask & num) {
                res ++;
            }
        }

        
        res += max_idx - 1;
        return res;
    }
};

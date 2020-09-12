// 260. Single Number III

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        

        int x = 0;
        for(int i: nums) {
            x ^= i;
        }
        
        int bit;
        int idx = 1;
        for(int i = 0; i < 32; i++) {
            if(x & idx) {
                bit = i;
                break;
            }
            idx <<= 1;
        }
        
        int first = 0;
        for(int i :nums) {
            if(i & 1 << bit) {
                first ^= i;
            }
        }
        
        return {first,first^x};
    }
};
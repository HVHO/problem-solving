// 70. Climbing Stairs    


class Solution {
public:
    
    int mem[46] = {0};
    
    int dp(int n) {
        if(mem[n]) return mem[n];
        return mem[n] = dp(n-1) + dp(n-2);
    }
    
    int climbStairs(int n) {
        mem[1] = 1;
        mem[2] = 2;
        return dp(n);
        
    }
};

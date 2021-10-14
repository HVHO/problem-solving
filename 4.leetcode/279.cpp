// 279. Perfect Squares

class Solution {
public:
    int numSquares(int n) {
        vector<int> mem(n+1,INT_MAX);
        for(int i=0; i <= n; i++)
            mem[i] = i;
        
        for(int i = 0; i <= n; i++) {
            for(int j = 1; j <= (int)sqrt(n - i); j++) {
                int next = i + j*j;
                if(mem[next] > mem[i] + 1)
                    mem[next] = mem[i] + 1;
            }
        }
        
        return mem[n];
    }
};

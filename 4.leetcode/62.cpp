// 62. Unique Paths

class Solution {
public:
    int uniquePaths(int m, int n) {
        int res = 0;
        vector<vector<int>> mem(m+1,vector<int>(n+1,0));
        
        mem[0][0] = 1;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                mem[i+1][j] += mem[i][j];
                mem[i][j+1] += mem[i][j];
            }
        }
        
        return mem[m-1][n-1];
    }
};

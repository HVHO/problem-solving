// 221. Maximal Square

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        auto mem = vector<vector<int>>(n,vector<int>(m,0));
        
        int res = 0;
        for(int i = 0; i < n; i++) {
            mem[i][0] = matrix[i][0] - '0';
            if(mem[i][0]) res = 1;
        }
            
        for(int i = 0; i < m; i++) {
            mem[0][i] = matrix[0][i] - '0';
            if(mem[0][i]) res = 1;
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == '1') {
                    mem[i][j] = min(mem[i-1][j-1],min(mem[i-1][j],mem[i][j-1])) + 1;
                    res = max(mem[i][j],res);
                }
            }
        }
        return res*res;
    }
};

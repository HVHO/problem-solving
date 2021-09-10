// 764. Largest Plus Sign

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) { 
        int l[n][n];
        int r[n][n];
        int u[n][n];
        int d[n][n];
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                l[i][j] = r[i][j] = u[i][j] = d[i][j] = 1;
        
        for(auto mine: mines) {
            int x = mine[0];
            int y = mine[1];
            l[x][y] = r[x][y] = u[x][y] = d[x][y] = 0;
        }
        
        for(int i = 0; i < n; i++)
            for(int j = 1; j < n; j++) {
                if(l[i][j]) l[i][j] = l[i][j-1] + 1;
                if(r[i][n-1-j]) r[i][n-1-j] = r[i][n-j] + 1;
                if(u[j][i]) u[j][i] = u[j-1][i] + 1;
                if(d[n-1-j][i]) d[n-1-j][i] = d[n-j][i] + 1;
            }
        
        
        int res = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                res = max(res,min(min(l[i][j],r[i][j]),min(u[i][j],d[i][j])));
        
        return res;
    }
};

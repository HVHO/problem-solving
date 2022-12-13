// 931. Minimum Falling Path Sum
class Solution {
    int dx[3] = {1, 1, 1};
    int dy[3] = {-1, 0, 1};
    int mem[1000][1000] = {0,};
    int n, m;
public:
    int dfs(int x, int y,vector<vector<int>>& mat) {
        if(x == (n - 1)) return mat[x][y];
        if(mem[x][y]!=INT_MAX) return mem[x][y];

        int res = INT_MAX;
        for(int i = 0; i < 3; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < n && 0 <= ny && ny < m) {
                int temp = dfs(nx,ny,mat);
                if(temp < res) res = temp;
            }
        }
        res += mat[x][y];
        mem[x][y] = res;

        return res;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++)
                mem[i][j] = INT_MAX;

        int res = INT_MAX;
        for(int i = 0; i < m; i++) {
            int t = dfs(0,i,matrix);
            if(res > t) res = t;
        }

        return res;
    }
};

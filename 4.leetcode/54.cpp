// 54. Spiral Matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int d[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int move[] = {m, n-1};
        
        bool visit[n][m];

        
        int dir = 0;
        int x = 0, y = -1;
        vector<int> res;
        while(move[dir%2]) {
            int cmove = move[dir%2]--;
            for(int i = 0; i < cmove; i++) {
                x += d[dir][0];
                y += d[dir][1];
                // printf("%d %d\n",x,y);
                res.push_back(matrix[x][y]);
            }
            dir = (dir+1)%4;
        }
        
        return res;
    }
};

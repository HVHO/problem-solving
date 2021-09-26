// 1293. Shortest Path in a Grid with Obstacles Elimination

class Solution {
public:
    
    int d[4][2] = {{0,1}, {1,0}, {0,-1},{-1,0}};
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        auto mem = vector<vector<int>>(n);
        for(int i = 0; i < n; i++) {
            mem[i] = vector<int>(m, -1);
        }
        
        queue<tuple<int,int,int>> q;
        q.push(make_tuple(0,0,k));
        
        int dep = 0;
        while(q.size()) {
            for(int qsize = q.size(); qsize--;) {
                auto [x, y, remain] = q.front();
                // printf("%d %d\n", x, y);
                q.pop();
                if(x == (n-1) && y == (m-1)) return dep;
                for(auto _d: d) {
                    int nx = x + _d[0];
                    int ny = y + _d[1];
                    if(0<=nx&&nx<n &&0<=ny&&ny<m) {
                        if(grid[nx][ny] && remain && ((remain-1) > mem[nx][ny])) {
                            mem[nx][ny] = remain-1;
                            q.push(make_tuple(nx,ny,remain-1));
                        }
                        if(!grid[nx][ny] && (remain > mem[nx][ny])) {
                            mem[nx][ny] = remain;
                            q.push(make_tuple(nx,ny,remain));
                        }
                    }
                }
            }
            dep++;
        }
        
        return -1;
    }
};

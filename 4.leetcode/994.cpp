// 994. Rotting Oranges


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int d[][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 2) q.push({i,j});
        
        int depth = 0;
        while(q.size()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                for(auto _d : d) {
                    int nx = x + _d[0];
                    int ny = y + _d[1];
                    
                    if(0<=nx&&nx<n&&0<=ny&&ny<m
                       && grid[nx][ny] == 1
                        ) {
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                    }
                }
            }
            depth++;
        }
        
        bool flag = true;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 1) flag = false;
        
        return flag ? (depth > 0 ? depth - 1 : 0) : -1;
    }
};

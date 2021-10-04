// 463. Island Perimeter

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        int d[][2] = {{-1,0},{0,-1}};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {   
                    res += 4;
                    for(auto _d: d) {
                        int nx = i + _d[0];
                        int ny = j + _d[1];
                        if(0<=nx&&0<=ny&&grid[nx][ny]) res -= 2;
                    }
                }
            }
        }
        return res;
    }
};

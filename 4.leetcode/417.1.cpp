// 417. Pacific Atlantic Water Flow

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        int n = heights.size();
        int m = heights[0].size();
        
        queue<pair<int,int>> q;
        
        auto pmap = vector<vector<int>>(n,vector<int>(m,0));
        
        for(int i = 0; i < n; i++) { q.push({i,0});}
        for(int i = 0; i < m; i++) { q.push({0,i});}
        
        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            if(pmap[x][y]) continue;
            pmap[x][y] = 1;
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                if(heights[x][y] <= heights[nx][ny]) {
                    q.push({nx,ny});
                }
            }
        }
        
        
        auto amap = vector<vector<int>>(n,vector<int>(m,0));
        
        for(int i = 0; i < n; i++) { q.push({i,m-1});}
        for(int i = 0; i < m; i++) { q.push({n-1,i});}
        
        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            if(amap[x][y]) continue;
            amap[x][y] = 1;
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                if(heights[x][y] <= heights[nx][ny]) {
                    q.push({nx,ny});
                }
            }
        }
        vector<vector<int>> res;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                if(pmap[i][j] && amap[i][j])
                    res.push_back(vector<int>({i,j}));
            }
        
        return res;
    }
};

// 417. Pacific Atlantic Water Flow    

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        if(!m) return vector<vector<int>>(0);
        int n = matrix[0].size();
        
        
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; // r, d, l, u
        bool pVisit[151][151] = {false,};
        
        queue<pair<int,int>> q;
        
        for(int i = 0; i < m; i++) {
            q.push(make_pair(i,0));
            pVisit[i][0] = true;
        }
        for(int i = 1; i < n; i++) {
            q.push(make_pair(0,i));
            pVisit[0][i] = true;
        }
        
        while(q.size()) {
            auto [x,y] = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                
                if(0<=nx && nx < m &&
                   0<= ny && ny < n &&
                   matrix[x][y] <= matrix[nx][ny] &&
                   !pVisit[nx][ny]
                  ) {
                    pVisit[nx][ny] = true;
                    q.push(make_pair(nx,ny));
                }
            }
        }
        
        bool aVisit[151][151] = {false,};
        
        vector<vector<int>> res;
        
        for(int i = 0; i < m; i++) {
            q.push(make_pair(i,n-1));
            aVisit[i][n-1] = true;
        }
        for(int i = 0; i < n - 1; i++) {
            q.push(make_pair(m-1,i));
            aVisit[m-1][i] = true;
        }
        
        while(q.size()) {
            auto [x,y] = q.front();
            q.pop();
            
            if(pVisit[x][y]) {
                vector<int> tmp;
                tmp.push_back(x);
                tmp.push_back(y);
                res.push_back(tmp);
            }
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                
                if(0<=nx && nx < m &&
                   0<= ny && ny < n &&
                   matrix[x][y] <= matrix[nx][ny] &&
                   !aVisit[nx][ny]
                  ) {
                    aVisit[nx][ny] = true;
                    q.push(make_pair(nx,ny));
                    
                }
            }
        }

        return res;
    }
};

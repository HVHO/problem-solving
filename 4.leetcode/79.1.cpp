// 79. Word Search

class Solution {
public:
    int d[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    
    bool dfs(int idx, int x, int y,vector<vector<bool>> &visit, string &word,vector<vector<char>>& board) {
        if(idx == word.length()) return true;
        
        int n = board.size();
        int m = board[0].size();
        for(auto _d: d) {
            int nx = x + _d[0];
            int ny = y + _d[1];
            if(0<=nx&&nx<n&&0<=ny&&ny<m&&!visit[nx][ny]) {
                if(board[nx][ny] == word[idx]) {
                    visit[nx][ny] = true;
                    if(dfs(idx + 1, nx, ny, visit, word, board)) return true;
                    visit[nx][ny] = false;
                }
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j]==word[0]) {
                    auto visit = vector<vector<bool>>(n,vector<bool>(m,false));
                    visit[i][j] = true;
                    if(dfs(1,i,j,visit,word,board)) return true;
                } 
            }
        }
        return false;
    }
};

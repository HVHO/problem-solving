// 1275. Find Winner on a Tic Tac Toe Game

class Solution {
public:
    
    int checkWin(vector<vector<char>>& b) {
        
        for(int i = 0; i < 3; i++) {
            if(b[i][0] == b[i][1] && b[i][1] == b[i][2]) {
                if(b[i][0] == 'X') return 1;
                if(b[i][0] == 'O') return 2;
            }
            
            if(b[0][i] == b[1][i] && b[1][i] == b[2][i]) {
                if(b[0][i] == 'X') return 1;
                if(b[0][i] == 'O') return 2;
            }
        }
        
        if(b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
            if(b[1][1] == 'X') return 1;
            if(b[1][1] == 'O') return 2;
        }
        
        if(b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
            if(b[1][1] == 'X') return 1;
            if(b[1][1] == 'O') return 2;
        }
        
        bool flag = true;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(b[i][j] == ' ') flag = false;
        
        return flag? 0 : 3;
    }
    
    string tictactoe(vector<vector<int>>& moves) {
        
        vector<vector<char>> board(3);
        for(int i = 0; i < 3; i++)
            board[i] = vector<char>(3,' ');
        
        int idx = 0;
        for(auto move: moves) {
            board[move[0]][move[1]] = idx%2 ? 'O' : 'X';
            idx++;
        }
        
        int winner = checkWin(board);
        
        string res;
        switch(winner) {
            case 0 : 
                res = "Draw";
                break;
            case 1 :
                res = "A";
                break;
            case 2 :
                res = "B";
                break;
            case 3 :
                res = "Pending";
                break;
        }
        
        return res;

    }
};

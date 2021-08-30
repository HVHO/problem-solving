#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

pair<int,int> d[3] = {{1,0}, {0,1}, {0,-1}};

bool bfs(vector<string> &p, pair<int,int> xy) {
    
    
    auto[x,y] = xy;
    queue<tuple<int,int,int>> q;
    q.push({x, y, 0});
    
    while(q.size()) {
        
        auto [tx, ty, depth] = q.front();
        q.pop();
        if((tx!=x || ty!=y) && p[tx][ty] == 'P') return false;
        if(depth < 2) {
            for(auto [dx, dy] : d) {
                int nx = tx + dx;
                int ny = ty + dy;
                if(nx < 5 && 0 <= ny && ny < 5 && p[nx][ny] != 'X') 
                    q.push({nx, ny, depth + 1});
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for(auto &place : places) {
        bool flag = true;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++)
                if(place[i][j] == 'P' && !bfs(place, {i,j})) {flag = false; goto A;}
        }
A:
        answer.push_back(flag? 1 : 0);
    }
    return answer;
}

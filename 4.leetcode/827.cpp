// 827. Making A Large Island


#define NMAX 501

using pi=pair<int,int>;

class Solution {
    pair<int,int> d1[2] = {{0,-1}, {-1,0}};
    pair<int,int> d2[4] = {{0,-1}, {-1,0}, {0,1}, {1,0}};
    
    int n;
    set<pi> mark[NMAX][NMAX] ;
    pi parent[NMAX][NMAX];
    vector<pi> member[NMAX][NMAX];
    
    void _union(pi a, pi b) {
        
        auto aparent = find(a);
        auto bparent = find(b);
        
        if(aparent == bparent) {
            return;
        } else {
            parent[bparent.first][bparent.second] = aparent;
            for(auto m: member[bparent.first][bparent.second]) {
                member[aparent.first][aparent.second].push_back(m);
            }
            member[bparent.first][bparent.second].clear();
            return;
        }
        
    }
    
    pi find(pi a) {
        if(parent[a.first][a.second] == a) return a;
        return parent[a.first][a.second] = find(parent[a.first][a.second]);
    }
    
    
public:
    
    int largestIsland(vector<vector<int>>& grid) {
        // init
        n = grid.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!grid[i][j]) continue;
                parent[i][j] = {i,j};    
                member[i][j].push_back({i,j});
            }
        }
        
        // union-find
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!grid[i][j]) continue;
                for(auto _d: d1) {
                    int ni = i + _d.first;
                    int nj = j + _d.second;
                    if(0<=ni && ni<n && 0<=nj && nj<n && grid[ni][nj]) {
                        _union({i,j},{ni,nj});
                    }
                }
            }
        }
        
        set<pi> meet;
        vector<pi> parents;
        // mark
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(member[i][j].size()) {
                    parents.push_back({i,j});
                    for(auto m: member[i][j]) {
                        for(auto _d: d2) {
                            int ni = m.first + _d.first;
                            int nj = m.second + _d.second;
                            if(0<=ni && ni<n && 0<=nj && nj<n && !grid[ni][nj]) {
                                if(mark[ni][nj].size()) 
                                    meet.insert({ni,nj});
                                mark[ni][nj].insert({i,j});
                            }
                        }
                        
                    }
                }
            }
        }
        
        vector<int> candi;
        
        if(!parents.size()) return 1;
        
        for(auto p: parents) {
            candi.push_back(member[p.first][p.second].size() + 1);
        }
        
        for(auto m: meet) {
            int _sum = 0;
            for(auto p: mark[m.first][m.second]) {
                 _sum += member[p.first][p.second].size();
            } 
            candi.push_back(_sum + 1);
        }
        
        sort(candi.rbegin(), candi.rend());
        return candi[0] > n*n ? n*n : candi[0];
    }
};

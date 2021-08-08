// 1632. Rank Transform of a Matrix

class Solution {
public:
    
    using pi=pair<int,int>;
    
    int n,m;
    
    vector<vector<bool>> visit;
    
    vector<vector<pi>> parent;
    vector<vector<vector<pi>>> members;
    vector<int> rowMaxVal;
    vector<int> colMaxVal;
    
    void _union(pi a, pi b) {
        auto aparent = find(a);
        auto bparent = find(b);
        
        if(aparent == bparent) {
            return;
        } else {
            
            if(members[aparent.first][aparent.second].size() < members[bparent.first][bparent.second].size()) {
                auto tmp = aparent;
                aparent = bparent;
                bparent = tmp;
            }
            
            parent[bparent.first][bparent.second] = aparent;
            for(auto _m: members[bparent.first][bparent.second]) {
                members[aparent.first][aparent.second].push_back(_m);
            }
            members[bparent.first][bparent.second].clear();
            return;
        }
    }
    
    pi find(pi a) {
        auto[x,y] = a;
        if(parent[x][y] == a) return a;
        else return parent[x][y] = find(parent[x][y]);
    }
    
    void update(pair<int,pi> a, vector<vector<int>>& matrix, vector<vector<int>> &rank) {
        auto [val, xy] = a;
        auto [x, y] = xy;
        if(visit[x][y]) return;

        
        int max_rank = 0;
        
        auto p = find(xy);
  
        for(auto _m: members[p.first][p.second]) {
            auto [mx,my] = _m;
            
            max_rank = max(max_rank,rowMaxVal[mx] + 1);
            max_rank = max(max_rank,colMaxVal[my] + 1);
        }
        
        for(auto _m: members[p.first][p.second]) {
            auto [mx, my] = _m;
            visit[mx][my] = true;
            rank[mx][my] = max_rank;
            rowMaxVal[mx] = max_rank;
            colMaxVal[my] = max_rank;
        }
        
        return;

    }
    
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        
        // init
        vector<vector<int>> rank (n);
        visit = vector<vector<bool>> (n);
        parent = vector<vector<pi>> (n);
        members = vector<vector<vector<pi>>> (n);
        rowMaxVal = vector<int> (n,0);
        colMaxVal = vector<int> (m,0);
        
        for(int i = 0; i < n; i++) {
            rank[i] = vector<int>(m,0);
            visit[i] = vector<bool>(m,false);
            parent[i] = vector<pi>(m);
            members[i] = vector<vector<pi>>(m);
            
            
            for(int j = 0; j < m; j++) {
                parent[i][j] = {i,j};
                members[i][j].push_back({i,j});
            }
        }
        
        // sort
        vector<pair<int,pi>> sorted;
        vector<pair<int,pi>> sorted2;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                sorted.push_back({matrix[i][j], {i,j}});
                sorted2.push_back({matrix[i][j], {j,i}});
            }
        
        sort(sorted.begin(),sorted.end());
        sort(sorted2.begin(),sorted2.end());
        
        // clustering same values
        for(int i = 0; i < n*m - 1; i++) {
                if(sorted[i].first == sorted[i+1].first
                   && sorted[i].second.first == sorted[i+1].second.first) {
                    _union(sorted[i].second, sorted[i+1].second);
                }
            
                if(sorted2[i].first == sorted2[i+1].first
                   && sorted2[i].second.first == sorted2[i+1].second.first) {
                    _union({sorted2[i].second.second,sorted2[i].second.first},{sorted2[i+1].second.second,sorted2[i+1].second.first});
                }
            
        }
        
        
        
        for(int i = 0; i < n*m; i++) {
            update(sorted[i], matrix, rank);
        }
                
        return rank;
    }
};

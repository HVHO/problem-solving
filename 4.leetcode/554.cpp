// 554. Brick Wall    

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
    return a.second > b.second;
}   

class Solution {
public:
    
    int leastBricks(vector<vector<int>>& wall) {
        
        map<int,int> m;
        
        for(int i = 0; i < wall.size(); i++) {
            int len = 0;
            for(int j = 0; j < wall[i].size() - 1; j++) {
                len += wall[i][j];
                if(m.find(len) != m.end()) {
                    m[len]++;
                } else {
                    m[len] = 1;
                }
            }
        }
        if(m.empty()) return wall.size();
        
        vector<pair<int,int>> v(m.begin(),m.end());
        sort(v.begin(), v.end(), cmp);
        
        return wall.size() - v[0].second;
    }
};

// 587. Erect the Fence

 
#define x first
#define y second

using ll=long long;
using pii=pair<int,int>;
    
pii operator-(pii a, pii b){ return {a.x-b.x, a.y-b.y}; }
ll cross(pii a, pii b){ return b.y*1LL*a.x - b.x*1LL*a.y; }
bool ccw(pii a, pii b, pii c){ return cross(b-a, c-a) > 0; }

class Solution {
public:
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<pii> v;
        for(auto tree: trees) {
            v.push_back({tree[0], tree[1]});
        }
        sort(v.begin(), v.end());
        
        vector<pii> uh; // upper hull
        vector<pii> lh; // lower hull
        int un = 0;
        int ln = 0;
        
        for(auto& t:v){
            while(un >= 2 && ccw(uh[un-2], uh[un-1], t)) uh.pop_back(), --un;
            uh.push_back(t);
            ++un;
        }
        
        reverse(v.begin(), v.end());
        
        for(auto& t:v){
            while(lh.size() >= 2 && ccw(lh[ln-2], lh[ln-1], t)) lh.pop_back(), --ln;
            lh.push_back(t);
            ++ln;
        }
        
        vector<vector<int>> res;
        
        uh.insert(uh.begin(),lh.begin(),lh.end());
        sort(uh.begin(), uh.end());
        uh.erase(unique(uh.begin(), uh.end()), uh.end());
        
        for(auto &h: uh) {
            res.push_back({h.x, h.y});
        }
        
        
        return res;
        
    }
};

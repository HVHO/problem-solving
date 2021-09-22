// 1239. Maximum Length of a Concatenated String with Unique Characters



class Solution {
public:
    
    void dfs(int idx, int val, int &res, vector<set<char>>& sv, set<char> s) {
        
        if(val > res) res = val;
        if(idx == sv.size()) return;
        
        dfs(idx + 1, val, res, sv, s);
        set<char> cs = sv[idx];
        for(auto c: cs) {
            if(s.find(c) != s.end()) return;
        }
        for(auto c: cs) {
            s.insert(c);
        }
        dfs(idx + 1, val + cs.size(), res, sv, s);
        return;
    }
    
    int maxLength(vector<string>& arr) {
        
        vector<set<char>> sv;
        for(auto s: arr) {
            set<char> sc;
            bool flag = true;
            for(auto c: s) {
                if(!sc.insert(c).second){
                    flag = false;
                    break;  
                } 
            }
            if(flag) sv.push_back(sc);
        }
        
        int res = 0;
        
        dfs(0, 0, res, sv, set<char>());
        
        return res;
    }
};

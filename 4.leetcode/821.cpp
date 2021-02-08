# 821. Shortest Distance to a Character    
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> idx;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == c) idx.push_back(i);
        }
        vector<int> res;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == c) res.push_back(0);
            else {
                int l = 0;
                int r = idx.size() - 1;
                int m;
                while(l + 1< r) {
                    m = (l + r)/2;
                    if(idx[m] > i) r = m;
                    else l = m;
                }
                res.push_back(min(abs(i - idx[l]),abs(idx[r] - i)));
            }
        }
        
        return res;
        
    }
};

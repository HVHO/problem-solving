// 524. Longest Word in Dictionary through Deleting    

class Solution {
public:
    
    static bool cmp(string a, string b) {
        if(a.length() == b.length()) {
            return a < b;
        } else {
            return a.length() > b.length();
        }
    }
    
    string findLongestWord(string s, vector<string>& d) {
        
        vector<int> idx[26];
        
        for(int i = 0; i < s.length(); i++) {
            idx[s[i] - 'a'].push_back(i);
        }
        
        sort(d.begin(), d.end(), cmp);
        
        for(auto s: d) {
            bool f1 = true;
            int p_idx = -1;
            for(auto c: s) {
                bool f2 = false;
                for(int i: idx[c - 'a']) {
                    if(i > p_idx) {
                        f2 = true;
                        p_idx = i;
                        break;
                    }
                }
                if(!f2) {
                    f1 = false;
                    break;
                }
            }
            if(f1) {
                return s;
            } 
        }
        
        return string();

    }
    
};

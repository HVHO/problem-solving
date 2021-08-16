// 76. Minimum Window Substring

class Solution {
public:
    
    bool check(int* l1, int* u1, int* l2, int* u2) {
        for(int i = 0; i < 26; i++) {
            if(l1[i] < l2[i]) return false;
            if(u1[i] < u2[i]) return false;
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        int n = s.length();
        int lt[26] = {0,};
        int ut[26] = {0,};
        
        for(auto c: t) {
            if(islower(c)) 
                lt[c-'a']++;
            else
                ut[c-'A']++;
        }
        
        int l = 0;
        int r = 0;
        
        string res = "";
        int ls[26] = {0,};
        int us[26] = {0,};
        while(r < n) {
            while(r < n && !check(ls,us,lt,ut)) {
                if(islower(s[r]))
                    ls[s[r]-'a']++;
                else
                    us[s[r]-'A']++;
                r++;
            }
            
            while(l < r && check(ls,us,lt,ut)){
                if(res == "" || res.length() > (r-l)) res = s.substr(l,(r-l));    
                if(islower(s[l]))
                    ls[s[l]-'a']--;
                else
                    us[s[l]-'A']--;
                l++;
            }

        }
        
        
        
        return res;
    }
};

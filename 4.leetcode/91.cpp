// 91. Decode Ways

class Solution {
public:
    
    int mem[1001] = {-1, };
    
    int dfs(int idx, string &s) {
        // memo
        if(mem[idx] != -1) return mem[idx];
        // terminal
        if(idx == s.length()) return 1;
        
        int res = 0;
        
        if(s[idx] != '0') res += dfs(idx+1, s);
        
        if(idx < s.length() - 1) {
            int num = (s[idx] - '0')*10 + (s[idx + 1] - '0');
            if( num >= 10 && num <= 26)
                res += dfs(idx+2, s);
        }
        
        return mem[idx] = res;
    }
    
    int numDecodings(string s) {
        for(int i = 0; i < 1001; i++)
            mem[i] = -1;
        return dfs(0, s);
    }
};

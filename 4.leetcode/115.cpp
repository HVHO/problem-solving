// 115. Distinct Subsequences

using ull = unsigned long long;

class Solution {
public:
    
    int numDistinct(string s, string t) {
        
        int sn = s.length();
        int tn = t.length();
        
        vector<vector<ull>> mem = vector<vector<ull>>(sn + 1);
        for(int i = 0; i <= sn; i++)
            mem[i] = vector<ull>(tn + 1,0);
        for(int i = 0; i <= sn; i++)
            mem[i][0] = 1;
        
        for(int i = 1; i <= tn; i++)
            for(int j = 1; j <= sn; j++)
                mem[j][i] += (s[j - 1] == t[i - 1]) ?  mem[j-1][i-1] + mem[j-1][i] : mem[j-1][i];

        
        return mem[sn][tn];
    }
};

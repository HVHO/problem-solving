// 848. Shifting Letters

class Solution {
public:
    
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        vector<long long> sl(n, 0);
        sl[n - 1] = shifts[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            sl[i] = sl[i + 1] + shifts[i];
        }
        for(int i = 0; i < n; i++) {
            s[i] = 'a' + (s[i] - 'a' + sl[i])%26;
        }
        
        return s;
    }
};

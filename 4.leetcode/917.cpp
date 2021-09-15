// 917. Reverse Only Letters

class Solution {
public:
    
    string reverseOnlyLetters(string s) {
        string r = s;
        reverse(r.begin(),r.end());
        
        int idx = 0;
        for(int i = 0; i < s.size(); i++) {
            if(isalpha(s[i])) {
                while(!isalpha(r[idx])) idx++;
                s[i] = r[idx++];
            }
        }
        
        return s;
    }
};

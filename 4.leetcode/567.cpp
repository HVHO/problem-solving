// 567. Permutation in String

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = s1.length();
        if(l > s2.length()) return false;

        auto m = vector<int>(26, 0);
        auto w = vector<int>(26, 0);

        for(int i = 0; i < l; i++) {
            m[s1[i] - 'a'] ++;
            w[s2[i] - 'a'] ++;
        }

        if(m==w) return true;

        for(int i = l; i < s2.length(); i++) {
            w[s2[i - l] - 'a']--;
            w[s2[i] - 'a']++;
            if(m==w) return true;
        }

        return false;
    }
};

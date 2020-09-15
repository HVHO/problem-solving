// 58.	Length of Last Word    

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int idx = s.length() - 1;
        while(idx >= 0 && s[idx] == ' ') {
            idx --;
        }
        while(idx >= 0 && s[idx] != ' ') {
            res ++;
            idx --;
        }
        return res;
    }
};
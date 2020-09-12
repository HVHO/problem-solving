// 409.Longest Palindrome    

class Solution {
public:
    int longestPalindrome(string s) {
        int cnt[53] = {0,};
        for(int i=0; i < s.size(); i++) {
            cnt[s[i] - ((s[i] - 'a') >= 0 ? 'a':('A' - 26))]++;
        }
        
        int res = 0;
        bool flag = false;
        for(int i=0;i<52;i++) {
            res+=cnt[i]/2;
            if(cnt[i]%2) flag = true;
        }
        return (2*res) + (flag?1:0);
        
    }
};
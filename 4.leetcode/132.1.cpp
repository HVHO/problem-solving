// 132.   Palindrome Partitioning II


class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        int dp[n+1];
        
        for(int i = 0; i <= n; i++)
            dp[i] = i - 1;
        
        for(int i = 0; i < n; i++) {
            int l,r;
            
            // expand even size palindrome
            l = i-1;
            r = i;
            for(;0<=l && r < n && s[l]==s[r]; l--&r++) {                
                dp[r+1] = min(dp[r+1],dp[l] + 1);
            }
            
            l = i;
            r = i;
            // expand odd size palindrome
            for(;0<=l && r < n && s[l]==s[r];l--&r++) {
                dp[r+1] = min(dp[r+1], dp[l] + 1);
            }
        }
        
        return dp[n];
        
    }
};

// 1143. Longest Common Subsequence

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        
        vector<vector<int>> lcs = vector<vector<int>>(n1 + 1);
        for(auto &l : lcs) {
            l = vector<int>(n2 + 1, 0);
        }
        
        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                if(text1[i-1]==text2[j-1]) {
                    lcs[i][j] = lcs[i-1][j-1] + 1; 
                } else {
                    lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
                }
            }
        }
        
        return lcs[n1][n2];
    }
};

// 300. Longest Increasing Subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 1;
        int dp[2500];
        
        for(int i = 0; i < 2500; i++) dp[i] = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
            if(res < dp[i]) res = dp[i];
        }
        
        return res;
    }
};

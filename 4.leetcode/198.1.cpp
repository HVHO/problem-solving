// 198. House Robber

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        auto mem = vector<vector<int>> (n, vector<int>(2,0));
        
        mem[0][0] = 0;
        mem[0][1] = nums[0];
        for(int i = 1; i < n; i++) {
            mem[i][0] = max(mem[i-1][0], mem[i-1][1]);
            mem[i][1] = max(mem[i-1][1], mem[i-1][0] + nums[i]);
        }
        return max(mem[n-1][0],mem[n-1][1]);
    }
};

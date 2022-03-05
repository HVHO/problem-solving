// 740. Delete and Earn

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> cnts(10001,0);
        
        for(auto num: nums)
            cnts[num]++;

        int mem[10001][2] = {0,};
        
        for(int i = 1; i < 10001; i++) {
            mem[i][0] = max(mem[i-1][1],mem[i-1][0]);
            mem[i][1] = mem[i-1][0] + i*cnts[i];
        }
        
        return max(mem[10000][0],mem[10000][1]);
        
    }
};

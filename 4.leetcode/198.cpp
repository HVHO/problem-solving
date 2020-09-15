//198.	House Robber   
// dfs
class Solution {
public:
    
    void dfs(vector<int>*nums, int idx, bool flag, int val, int &max, int remain) {
        
        if(idx >= (*nums).size()) {
            if(val > max) max = val;
            return;
        }
    
        // 
        if(max > val + remain) return;
        
        if(!flag) dfs(nums, idx + 1, true, val + (*nums)[idx], max, remain - (*nums)[idx]);
        dfs(nums, idx + 1, false, val, max,  remain - (*nums)[idx]);
        
        return;
    }
    
    int rob(vector<int>& nums) {
        
        int res = 0;
        int remain = 0;
        for(int i: nums) {
            remain += i;
        }
        dfs(&nums, 0, false, 0, res, remain);
        
        return res;
        
    }
};

// dp
// define dp[i] : maximum value that i'th house selected

#define max(x,y) ((x) > (y)? (x):(y))

class Solution {
public:
    
    int dp(vector<int> *nums, vector<int> *mem, int idx) {
        
        // init
        if(idx < 2) return (*nums)[idx];
        // dp
        if((*mem)[idx]) return (*mem)[idx];
        else {
            (*mem)[idx] = max(dp(nums,mem, idx - 1), dp(nums,mem, idx - 2) + (*nums)[idx]);
            return (*mem)[idx];
        }
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        
        int size = nums.size();
        vector<int> mem(size+1,0);
        nums.push_back(0);
        return dp(&nums,&mem,size+1);
    }
};
// 698. Partition to K Equal Sum Subsets

class Solution {
public:
    
    bool dfs(int curSum, int target, int count, int stIdx, vector<bool> &visit, vector<int> &nums) {
        int n = nums.size();
        if(count == n) return true;
        if(curSum == target) return dfs(0, target, count, 0, visit, nums);
        for(int i = stIdx; i < n; i++) {
            if(!visit[i] && (curSum + nums[i]) <= target) {
                visit[i] = true;
                if(dfs(curSum + nums[i], target, count+1, i+1, visit, nums)) return true;
                visit[i] = false;
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int s = 0;
        for(auto num: nums) {
            s += num;
        }
        if(s%k) return false;
        int avg = s/k;
        for(auto num: nums) {
            if(num > avg) return false;
        }
        // sort(nums.begin(),nums.end());
        vector<bool> visit = vector<bool>(nums.size(),false);
        return dfs(0, avg, 0, 0, visit, nums);
    }
};

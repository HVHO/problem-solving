// 673.	Number of Longest Increasing Subsequence  
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int,int>> mem(nums.size(),make_pair(1,1)); // pair(length, nums)
        
        for(int i = 0; i < nums.size(); i++) {
            int cur_len = 1;
            int cur_cnt = 1;
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    if(mem[j].first + 1 > cur_len) {
                        cur_len = mem[j].first + 1;
                        cur_cnt = mem[j].second;
                    } else if (mem[j].first + 1 == cur_len) {
                        cur_cnt += mem[j].second;
                    }
                }
                mem[i] = make_pair(cur_len, cur_cnt);
            }
        }
        
        int max_len = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            // cout<<"idx: " <<i << " len: "<<mem[i].first <<" cnt: "<<mem[i].second<<endl;
            if(max_len < mem[i].first) {
                max_len = mem[i].first;
                cnt = mem[i].second;
            } else if (max_len == mem[i].first) {
                cnt += mem[i].second;
            }
        }
        
        return cnt;

    }
};

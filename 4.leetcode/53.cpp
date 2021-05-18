// 53. Maximum Subarray    

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int acc[30001] = {0};

        for(int i = 0; i < nums.size(); i++) {
            acc[i+1] = acc[i] + nums[i];
        }
        
        int res = INT_MIN;
        int local_min = 0;
        for(int i = 1; i <= nums.size(); i++) {
            
            if(res < acc[i] - local_min) res = acc[i] - local_min;
                
            if(acc[i] < local_min) local_min = acc[i];
        }
        
        return res;
    }
};

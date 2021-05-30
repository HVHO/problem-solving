// 164. Maximum Gap    


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 1; i <nums.size(); i++) {
            if(res < nums[i] - nums[i-1]) {
                res = nums[i] - nums[i-1];
            }
        }
        return res;
    }
};

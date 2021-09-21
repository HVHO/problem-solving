// 485. Max Consecutive Ones


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        
        int t = 0;
        for(auto i : nums) {
            if(i) {
                t++;
                res = max(res,t);
            } else {
                t = 0;
            }
        }
        
        return res;
    }
};

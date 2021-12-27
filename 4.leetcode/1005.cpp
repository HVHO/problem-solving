// 1005. Maximize Sum Of Array After K Negations

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int idx = 0;
        while(k&&(idx<n)&&(nums[idx]<0)) {
            nums[idx] *= -1;
            idx++,k--;
        }
        sort(nums.begin(),nums.end());
        if(k&1) {
            nums[0] *= -1;
        }

        int res = 0;
        for(auto c: nums)
            res += c;

        return res;
    }
};

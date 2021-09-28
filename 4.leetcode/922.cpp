// 922. Sort Array By Parity II

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 1;
        while(l < n && r < n) {
            while(l < n && !(nums[l]&1)) l+=2;
            while(r < n && nums[r]&1) r+=2;
            if(l < n && r < n) {
                int t = nums[l];
                nums[l] = nums[r];
                nums[r] = t;    
            }
        }
        return nums;
    }
};

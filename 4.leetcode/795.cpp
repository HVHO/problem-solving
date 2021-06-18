// 795. Number of Subarrays with Bounded Maximum    


class Solution {
public:
    
    int count(vector<int>& nums, int bound) {
        int count = 0;
        int res = 0;
        for(auto num: nums) {
            res += count = num > bound ? 0 : ++count;
        }
        
        return res;
    }
    
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {    
        return count(nums, right) - count(nums, left - 1);
    }
};

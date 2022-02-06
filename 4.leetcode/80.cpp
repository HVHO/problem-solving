// 80. Remove Duplicates from Sorted Array II

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1;
        int idx = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) {
                if(cnt < 2) {
                    nums[idx++] = nums[i];
                }
                cnt++;
            } else {
                cnt = 1;
                nums[idx++] = nums[i];
            }
        }
        
        return idx;
    }
};

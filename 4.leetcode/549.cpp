

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int size = nums.size();
        vector<int> lower(size+1);
        vector<int> same(size+1);
        vector<int> higher(size+1);
        
        for(int i = 1; i < size; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] == nums[j]) {
                    same[i] = same[j] + 1;
                    lower[i] = max(lower[j]? lower[j] + 1 : 0, lower[i]);
                    higher[i] = max(higher[j]? higher[j] + 1 : 0, higher[i]);
                } else if (nums[i] == (nums[j] - 1)) {
                    higher[i] = max(lower[j] + 1, higher[i]);
                    higher[i] = max(same[j] + 1, higher[i]);
                } else if (nums[i] == (nums[j] + 1)) {
                    lower[i] = max(higher[j] + 1, lower[i]);
                    lower[i] = max(same[j] + 1, lower[i]);
                }
            }
        }
        
        int res = 0;
        for(int i = 0; i < size; i++) {
            if(res < lower[i]) res = lower[i];
            if(res < higher[i]) res = higher[i];
        }
        
        return res? res + 1: 0;
        
    }
};

// 16. 3Sum Closest

class Solution {
public:
    
    int diff(int a, int b) {
        return abs(a-b);
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 1e7;
        int len = nums.size();
        
        sort(nums.begin(), nums.end());
        

        for(int i = 0; i < len - 2; i++) {
            int j = i + 1, k = len - 1;
            
            while(j < k) {
                int sum3 = nums[i] + nums[j] + nums[k];
                if(diff(target, res) > diff(target,sum3)) res = sum3;
                if(sum3 > target) {
                    k--;
                } else if (sum3 < target) {
                    j++;
                } else {
                    return target;
                }
            }
            
        }
        
        return res;
        
    }
};

// 15. 3Sum

#include<algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        if(nums.size() < 3) return res;
        sort(nums.begin(),nums.end());
        
        int* i,j,k;
        
        for(int i = 0; i < nums.size() - 2; i++) {
            j = i+1;
            k = nums.size()-1;
            
            int sum;
            while(j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if(!sum) {
                    res.push_back(vector<int>{nums[i],nums[j],nums[k]});
                    do{k--;j++;} while(j < k && nums[k]==nums[k+1] && nums[j]==nums[j-1]);
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
            
            while(i < nums.size() - 2 && nums[i] == nums[i+1]) i++;
        }
        
        return res;
        
    }
};

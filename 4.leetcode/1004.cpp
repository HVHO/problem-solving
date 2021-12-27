// 1004. Max Consecutive Ones III

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        
        int res = 0;
        int t = nums[0];
        for(int i = 1; i < n; i++)
            if(nums[i]) res = max(res,++t);
            else t = 0;
        int l = 0, r = 0;
        
        while(l<=r && r<n) {
            while(r<n) {
                if(nums[r]) r++;
                else if(k) k--,r++;
                else break;
            }
            // printf("%d %d %d\n",l,r,k);
            res = max(res,r-l);
            if(!nums[l]) k++;
            l++;
        }
        
        return res;
    }
};

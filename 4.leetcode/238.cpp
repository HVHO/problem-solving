// 238. Product of Array Except Self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n+2,1);
        vector<int> r(n+2,1);
        
        for(int i = 0; i < n; i++) {
            l[i+1] = l[i] * nums[i];
            r[n-i] = r[n-i+1] * nums[n-i-1];
        }
        
        vector<int> res;
        for(int i = 0; i < n; i++) {
            res.push_back(l[i]*r[i+2]);
        }
        return res;
    }
};

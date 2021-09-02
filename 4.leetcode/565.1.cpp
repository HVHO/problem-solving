class Solution {
public:
   
    
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> v(n, false);
        int res = 1;
        
        for(int i = 0; i < n; i++) {
            if(v[i]) continue;
            int c = i, n = nums[c], dep = 1;
            while((v[c] = true) && !v[n]) {
                dep++;
                c = n;
                n = nums[c];
                if(dep > res) res = dep;
            }
        }
        
        return res;
    }
};

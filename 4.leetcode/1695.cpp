// 1695. Maximum Erasure Value

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int l = 0;
        int r = 0;
        
        
        int max = 0;
        int sum = 0;
        map<int,int> m;
        while(r<nums.size()) {
            if(m.find(nums[r])==m.end()) { // not exist
                sum += nums[r];
                if(max < sum) max = sum;
                m.insert(make_pair(nums[r],r));
                r++;
            } else {
                int idx = m[nums[r]];
                
                for(int i = l; i <= idx; i++) {
                    m.erase(nums[i]);
                    sum -= nums[i];
                }
                l = idx + 1;
            }
        }
        
        return max;
    }
};

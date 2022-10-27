// 523. Continuous Subarray Sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        
        int s = 0;
        for(int i=0; i < nums.size(); i++) {
            s += nums[i];
            int key = s%k;
            if(i>0&&key == 0) return true;
            if(m.find(key) != m.end()) {
                if((i - m[key]) > 1) return true;
                continue;
            }
            else m[key] = i;
        }
        
        return false;
    }
};

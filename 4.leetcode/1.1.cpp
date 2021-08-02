// 1. Two Sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> nps;
        int len = nums.size();
        for(int i = 0; i < len; i++)
            nps.push_back({nums[i],i});
        
        sort(nps.begin(), nps.end());
        
        int i = 0;
        int j = len - 1;
        while(i < j) {
            int s = nps[i].first + nps[j].first;

            
            if(s == target) {
                vector<int> res;
                res.push_back(nps[i].second);
                res.push_back(nps[j].second);
                return res;
            } else if ( s < target ) {
                i++;
            } else {
                j--;
            }
        }
        
        return vector<int>();
        
    }
};

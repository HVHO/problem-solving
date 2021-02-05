#include<map>

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int size = nums.size();
        map<int,int> map;
        
        for(int i = 0; i < size; i++) {
            if(map.find(nums[i]) != map.end()) {
                map.find(nums[i]) -> second++;
            } else {
                map.insert(make_pair(nums[i],1));
            }
        }
        
        int res = 0;
        pair<int,int> prev = make_pair(INT_MIN,0);

        for(auto iter: map) {
            if(prev.first == (iter.first - 1)) {
                if(res < iter.second + prev.second)
                    res = iter.second + prev.second;
            }
            prev = iter;
        }
        
        return res;   
        
    }
};

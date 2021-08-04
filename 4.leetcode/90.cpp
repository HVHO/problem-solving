// 90. Subsets II


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        set<unsigned long long> s;// nums => -10 ~ 10 -> 21 가지 -> 5bit 로 표현 가능
        vector<int> mask(10);
        for(int i = 0; i <= len; i++) {
            
            for(int j = 0; j < i; j++ )
                mask[j] = 0;;
            for(int j = i; j < len; j++)
                mask[j] = 1;
            
            do {
                unsigned long long encoded = 31; // first 5 bit is all 1
                for(int k = 0; k < len; k++) {
                    if(mask[k]) {
                        encoded = encoded << 5;
                        encoded |= (nums[k] + 10);
                    }
                }
                s.insert(encoded);
            } while(next_permutation(mask.begin(), mask.end()));
        }
        
        vector<vector<int>> res;

        for(auto i: s) {
            vector<int> tmp;
            while((i&31ull) ^ 31ull) {
                int num = i & 31ull;
                i = i >> 5;
                tmp.push_back(num - 10);
            }
            res.push_back(tmp);
        }
        
        return res;
        
    }
};

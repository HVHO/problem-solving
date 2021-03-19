// 376. Wiggle Subsequence    
#include <math.h>

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> raise(nums.size(), 0); 
        vector<int> drop(nums.size(), 0); 
        int size = nums.size();
        raise[0] = 1;
        drop[0] = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] == nums[i]) {
                raise[i] = raise[i - 1];
                drop[i] = drop[i - 1];
            } else if (nums[i - 1] < nums[i]) {
                raise[i] = drop[i - 1] + 1;
                drop[i] = drop[i - 1];
            } else {
                raise[i] = raise[i - 1];
                drop[i] = raise[i - 1] + 1;
            }

        }
        
        return raise[size - 1] > drop[size - 1] ? raise[size - 1] : drop[size - 1];
        
    }
};

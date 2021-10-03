// 55. Jump Game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int zIdx = n;
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] == 0){
                zIdx = i;
                while(i >= 0 && nums[i] < (zIdx - i + 1)) i--;
                if(i < 0) return false;
            }
        }
        return true;
    }
};

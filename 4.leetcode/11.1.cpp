// 11. Container With Most Water   

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        
        int res = 0;
        
        while(l < r) {
            int tmp =  (height[l] < height[r]) ? height[l]*(r-l) : height[r]*(r-l);
            if(tmp > res) res = tmp;
            if(height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        
        
        return res;
    }
};

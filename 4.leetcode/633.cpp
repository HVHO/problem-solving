// 633. Sum of Square Numbers

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0;
        long long r = ceil(sqrt(c));

        while(l <= r) {
            long long s = l*l + r*r;
            if(s == c) {
                return true;
            } else if (s > c) {
                r--;
            } else {
                l++;
            } 
        }
        
        return false;
        
    }
};

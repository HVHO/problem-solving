// 258. Add Digits    

class Solution {
public:
    int addDigits(int num) {
        if(!num) return 0;
        return (num-1)%9 + 1;
    }
};
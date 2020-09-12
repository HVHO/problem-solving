// 470. Implement Rand10() Using Rand7()

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int row, col, res = 0;
        
        do{
            row = rand7();
            col = rand7();
            res = col + (row - 1)*7;
        } while(res > 40);
        
        return (res - 1)%10 + 1;
    }
};
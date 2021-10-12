// 374. Guess Number Higher or Lower

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
        long long l = 1;
        long long r = n;
        long long m;
        while(l<=r) {
            m = (l+r)/2;
            int g = guess(m);
            
            if(g == 0) return m;
            else if (g == 1) l = m + 1;
            else r = m - 1;
        }
        
        return 0;
    }
};

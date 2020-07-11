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
        
        long long m = (l + r)/2;
        int x;
        while((x = guess(m))!=0) {
            if(x == -1) r = m - 1;
            else l = m + 1;
            m = (l+r)/2;
        }
        
        return m;
    }
};
// 204. Count Primes    

class Solution {
public:
    int countPrimes(int n) {
        
        vector<bool> isPrime(n + 1,true);
        int res = 0;
        for(int i = 2; i < n; i++) {
            if(isPrime[i]) {
                // cout << i << " " << endl;
                res++;
                int j = 1;
                while((++j)*i<= n) {
                    isPrime[i*j] = false;
                }
            }
        }
        
        return res;
        
    }
};

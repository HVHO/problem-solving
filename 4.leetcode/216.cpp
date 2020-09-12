// 216.	Combination Sum III    
#include<algorithm>

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> res;
        
        vector<int> perm(9 - k,0);
        for(int i = 0; i < k; i++) perm.push_back(1);
        
        do{
            int sum = 0;
            for(int i = 0; i < 9; i++) {
                if(perm[i]) sum += i+1;
            }
            if(sum == n) {
                vector<int> cur;
                for(int i = 0; i < 9; i++) {
                    if(perm[i]) cur.push_back(i+1);
                }
                res.push_back(cur);
            }
        } while(next_permutation(perm.begin(),perm.end()));
        
        return res;
    }
};
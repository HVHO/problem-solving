// 905.Sort Array By Parity 

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> even;
        vector<int> odd;
        
        for(int i = 0; i < A.size(); i++) {
            if(A[i]&1) odd.push_back(A[i]);
            else even.push_back(A[i]);
        }
        
        std::move(odd.begin(), odd.end(), std::back_inserter(even));
        
        return even;
    }
};
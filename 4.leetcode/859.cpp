//859.	Buddy Strings    

class Solution {
public:
    bool buddyStrings(string A, string B) {
        
        if(A.length() != B.length()) return false;
        
        vector<int> diff;
        
        for(int i = 0; i < A.length(); i++) {
            if(A[i]^B[i]) diff.push_back(i);
        } 
        
        if(diff.size() == 0) {
            int a[26] = {0,};
            bool flag = false;
            for(int i = 0; i < A.length(); i++) {
                a[A[i] - 'a']++;
                if((a[A[i] - 'a']) >= 2) flag = true;
            }
            return flag;
        }
        if(diff.size() != 2) return false;
        
        if(A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]]) return true;
        
        return false;
    }
};
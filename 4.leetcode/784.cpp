// 784. Letter Case Permutation    

class Solution {
public:
    
    void rec(string S, int idx, vector<char> buf, vector<string> &res) {
        if(idx == S.length()) {
            string tmp(buf.begin(), buf.end());
            res.push_back(tmp);
            return;
        }
        
        if('0' <= S[idx] && S[idx] <= '9') {
            buf.push_back(S[idx]);
            rec(S, idx + 1, buf, res);
        } else {
            buf.push_back(S[idx]);
            rec(S, idx + 1, buf, res);
            buf.pop_back();
            buf.push_back(S[idx] + 'A' - 'a');
            rec(S, idx + 1, buf, res);
        }
        return;
    }
    
    vector<string> letterCasePermutation(string S) {
        
        vector<string> res;
        vector<char> buf;
        for(int i = 0; i < S.length(); i++) {
            if(isupper(S[i])) {
                S[i] = tolower(S[i]);
            }
        }
        rec(S, 0, buf, res);
        return res;
    }
};

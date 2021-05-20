// 14. Longest Common Prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int idx;
        string res = "";
        int min_len=strs[0].size();
        for(int i = 0; i < strs.size(); i++)
            if(min_len > strs[i].size()) min_len = strs[i].size();
        
        for(int i = 0; i < min_len; i++) {
            bool flag = true;
            for(int j = 1; j < strs.size(); j++) {
                if(strs[j][i] ^ strs[j-1][i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                res.push_back(strs[0][i]);
            } else {
                break;
            }
        }
        return res;
    }
};

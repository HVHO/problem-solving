// 132. Palindrome Partitioning II


class Solution {
public:
    
    int minPalindrome[2001][2001] = {0,};
    int isPalindrome[2001][2001] = {0, };
    
    bool check_palindrome(int st, int ed, string &s) {
        if(isPalindrome[st][ed] != 0) 
            return isPalindrome[st][ed] == 1 ? true : false;
        
        bool res = true;
        int _st = st;
        int _ed = ed;
        while(_st < _ed) {
            if(s[_st++] != s[_ed--]) {
                res = false;
                break;
            }
        }
        isPalindrome[st][ed] = (res ? 1:-1);
        return res;
    }
    
    vector<int> get_palindrome_offsets(int st, int ed, string &s) { // return palindrome offsets from left
        vector<int> res;
        for(int i = ed; i >= st; i--) {
            if(check_palindrome(st, i, s)) res.push_back(i - st);
        }
        return res;
    }
    
    int dfs(int st, int ed, string &s) {
        
        if(minPalindrome[st][ed]) return minPalindrome[st][ed];
        
        if(st>ed) return 0;
        
        vector<int> offsets = get_palindrome_offsets(st, ed, s);
        
        int res = 2001;
        for(auto offset: offsets) {
            res = min(res,dfs(st + offset + 1, ed, s) + 1);
        }
        return minPalindrome[st][ed] = res;
    }
    
    int minCut(string s) {
        return dfs(0, s.length() - 1, s) - 1;
    }
};

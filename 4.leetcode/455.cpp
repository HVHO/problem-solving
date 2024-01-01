class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int res = 0;
        int j = 0;
        int sSize = s.size();
        int gSize = g.size();
        for(int i = 0; i < sSize; i++) {
            if(s[i] >= g[j]) {
                res++;
                j++;
                if(j >= gSize) break;
            }
        }

        return res;
    }
};
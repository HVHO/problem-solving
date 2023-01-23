// 997. Find the Town Judge

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int> m1;
        map<int,int> m2;

        if (n==1) return 1;

        for(auto t: trust) {
            if(m1.find(t[0]) == m1.end()) {
                m1[t[0]] = 1;
            } else {
                m1[t[0]] ++;
            }
            if(m2.find(t[1]) == m2.end()) {
                m2[t[1]] = 1;
            } else {
                m2[t[1]] ++;
            }
        }

        for(int i = 1; i <= n; i++) {
            if(m1.find(i) == m1.end()
             && m2.find(i) != m2.end() 
             && m2[i] == (n - 1))
             
             return i;
        }
        
        return -1;
    }
};

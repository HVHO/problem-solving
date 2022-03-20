// 1007. Minimum Domino Rotations For Equal Row

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        
        vector<int> tc(7,0);
        vector<int> bc(7,0);
        vector<int> sc(7,0);
        
        for(int i = 0; i < n; i++) {
            tc[tops[i]]++;
            bc[bottoms[i]]++;
            if(tops[i]==bottoms[i]) sc[tops[i]]++;
        }
        
        int ans = 20001;
        for(int i = 1; i <7; i++)
            if(tc[i] + bc[i] - sc[i] == n) ans = min(ans,min(tc[i],bc[i]) - sc[i]);
        return ans == 20001? -1:ans;
    }
};

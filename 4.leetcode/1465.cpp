// 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts    


class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        vector<int> hl;
        vector<int> vl;
        
        for(int i = 0; i < horizontalCuts.size() - 1; i++) {
            hl.push_back(horizontalCuts[i + 1] - horizontalCuts[i]);
        }
        hl.push_back(horizontalCuts[0]);
        hl.push_back(h - horizontalCuts[horizontalCuts.size()-1]);
        
        for(int i = 0; i < verticalCuts.size() - 1; i++) {
            vl.push_back(verticalCuts[i + 1] - verticalCuts[i]);
        }
        vl.push_back(verticalCuts[0]);
        vl.push_back(w - verticalCuts[verticalCuts.size() - 1]);
        
        sort(hl.begin(), hl.end());
        sort(vl.begin(), vl.end());
        
        return(hl[hl.size() - 1] * (long long)vl[vl.size() - 1])%1000000007ll;
        
    }
};


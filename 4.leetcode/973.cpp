// 973. K Closest Points to Origin

class Solution {
public:
    
    static int val(vector<int>&a) {
        return a[0]*a[0] + a[1]*a[1];
    }
    
    static bool compare(vector<int>& a, vector<int>& b) {
        return val(a) > val(b);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        make_heap(points.begin(),points.end(),compare);
        
        vector<vector<int>> res;
        for(int i = 0; i < k; i++) {
            res.push_back(points[0]);
            pop_heap(points.begin(),points.end(),compare);
            points.pop_back();
        }

        
        return res;
        
    }
};

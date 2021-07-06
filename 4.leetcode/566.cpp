
// 566. Reshape the Matrix

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(r*c ^ mat.size()*mat[0].size()) return mat;
        if(r == mat.size()) return mat;
        
        vector<vector<int>> res(r);
        for(int i = 0; i < r; i++)
            res[i] = vector<int>(c);
        
        int n = mat[0].size();
        for(int i = 0; i < r*c; i++) {
            res[i/c][i%c] = mat[i/n][i%n];
        }
        
        return res;
    }
};

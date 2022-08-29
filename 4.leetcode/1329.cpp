// 1329. Sort the Matrix Diagonally


class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> v;
        
        for(int i = 0; i < n; i++) {
            for(int k = 0; (i+k) < n && k < m; k++) {
                v.push_back(mat[i+k][k]);
            }
            sort(v.begin(),v.end());
            for(int k = 0; (i+k) < n && k < m; k++) {
                mat[i+k][k] = v[k];
            }
            v.clear();
        }
        
        for(int j = 1; j < m; j++) {
            for(int k = 0; k < n && (k + j) < m; k++) {
                v.push_back(mat[k][j+k]);
            }
            sort(v.begin(),v.end());
            for(int k = 0; k < n && (k + j) < m; k++) {
                mat[k][j+k] = v[k];
            }
            v.clear();
        }
        
        return mat;
    }
};

// 119. Pascal's Triangle II

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pascal[2];
        int idx = 0;
        
        pascal[0].reserve(34);
        pascal[1].reserve(34);
        
        
        for(int i = 0; i <= rowIndex; i++) {
            pascal[idx][0] = 1;
            for(int j = 1; j < i; j++) {
                pascal[idx][j] = pascal[(idx+1)%2][j-1] + pascal[(idx+1)%2][j];
            }
            pascal[idx][i] = 1;
            idx = (idx+1)%2;
        }
        
        return vector<int>(pascal[rowIndex%2].begin(),pascal[rowIndex%2].begin() + rowIndex + 1);
    }
};
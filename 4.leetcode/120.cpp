// 120. Triangle    

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int depth = triangle.size();
        // vector<vector<int>> mem(depth);
        // for(int i = 0; i < depth; i++) {
        //     mem[i] = vector<int>(i+1,0);
        // }
        int mem[201][201] = {0, };
        
        mem[0][0] = triangle[0][0];
        
        for(int i = 1; i < depth; i++) {
            for(int j = 0; j <= i; j++) {
                int l = INT_MAX;
                int r = INT_MAX;
                if(j!=0) {
                    l = mem[i-1][j-1];
                }
                if(j!=i) {
                    r = mem[i-1][j];
                }
                
                mem[i][j] = min(l,r) + triangle[i][j];
            }
        }
        int res = INT_MAX;
        for(int i = 0; i < depth; i++) {
            res = min(res,mem[depth-1][i]);
        }
        return res;
    }
};

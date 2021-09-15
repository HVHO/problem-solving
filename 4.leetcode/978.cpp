// 978. Longest Turbulent Subarray

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        
        auto u = vector<int>(n,1);
        auto d = vector<int>(n,1);
        
        
        int res = 1;
        
        for(int i = 1; i < n; i++){
            if(arr[i] > arr[i - 1]) {
                u[i] = d[i-1] + 1;
                res = max(res ,u[i]);
                d[i] = 1;
            } else if (arr[i] < arr[i - 1]) {
                d[i] = u[i-1] + 1;
                res = max(res, d[i]);
                u[i] = 1;
            } else {
                u[i] = d[i] = 1;
            }
        }
        
        return res;
    }
};

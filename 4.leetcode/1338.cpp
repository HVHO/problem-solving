// 1338. Reduce Array Size to The Half

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> v;
        
        int t = -1;
        int c = 0;
        for(auto i: arr) {
            if(t!=i) {
                v.push_back(c);
                t = i;
                c = 0;
            } 
            c++;
        }
        v.push_back(c);
        
        sort(v.rbegin(), v.rend());
        
        int res = 0;
        int sum = 0;
        for(auto i: v) {
            // cout << i << endl;
            res++;
            sum += i;
            if(sum >= arr.size()/2)
                break;
        }
        
        return res;
    }
};

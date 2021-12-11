// 1306. Jump Game III

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        
        vector<bool> visit(n,false);
        
        queue<int> q;
        q.push(start);
        
        while(q.size()) {
            int cur = q.front();
            q.pop();
            if(visit[cur]) continue;
            visit[cur] = true;
            
            if(arr[cur]==0) return true;
            if(cur + arr[cur] < n) q.push(cur + arr[cur]);
            if(cur - arr[cur] >= 0) q.push(cur - arr[cur]);
            
        }
        return false;
    }
};

// 1383. Maximum Performance of a Team    


class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) {
            v.emplace_back(efficiency[i],speed[i]);
        }
        
        sort(v.rbegin(),v.rend());
        long long speed_sum = 0;
        long long res = 0;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for(auto [e, s]: v) {
            speed_sum += s;
            min_heap.push(s);
            if(min_heap.size() > k) {
                while(min_heap.size() > k) {
                    speed_sum -= min_heap.top();
                    min_heap.pop();
                }
            }
            if(res < speed_sum*e) {
                res = speed_sum*e;
            }
            
        }
        return res%(int)(1e9 + 7);
    }
};

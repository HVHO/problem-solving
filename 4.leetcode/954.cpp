// 954. Array of Doubled Pairs


class Solution {
public:
    
    bool validate(vector<int>& arr) {
        int n = arr.size();
        
        if(n%2) return false;
        
        map<int,int> m;
        
        for(auto i: arr) {
            if(m.find(i) != m.end()) {
                m[i]++;
            } else {
                m[i] = 1;
            }
        }
        
        for(auto [i, cnt]: m) {
            if(cnt == 0) continue;
            if(m.find(2*i) == m.end()) return false;
            
            if(m[2*i] < cnt) return false;
            m[2*i] -= cnt;
        }
        
        return true;
    }
    
    bool canReorderDoubled(vector<int>& arr) {
        
        vector <int> positives;
        vector <int> negatives;
        int zcnt;
        for(auto i: arr) {
            if(i > 0) 
                positives.push_back(i);
            else if(i < 0)
                negatives.push_back(-i);
            else
                zcnt++;
        }
        
        if(zcnt%2) return false;
        if(!validate(positives)) return false;
        if(!validate(negatives)) return false;
        
        return true;
    }
};

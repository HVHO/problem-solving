// 923. 3Sum With Multiplicity  

#include <map>



class Solution {
public:
    
    long long combination(int n, int k)
    {
        if (k > n) return 0;
        if (k * 2 > n) k = n-k;
        if (k == 0) return 1;

        long long result = n;
        for( int i = 2; i <= k; ++i ) {
            result *= (n-i+1);
            result /= i;
        }
        return result;
    } 
    
    int threeSumMulti(vector<int>& arr, int target) {
        
        map<int,int> m;
        
        for(auto i: arr) {
            if(m.find(i) != m.end()) {
                m[i]++;
            } else {
                m[i]=1;
            }
        }
        vector<pair<int,int>> sorted;
        for(auto i: m) {
            sorted.push_back(i);
        }
        
        sort(sorted.begin(),sorted.end());
        
        // for(auto i: sorted) {
        //     cout << i.first << " " << i.second <<endl;
        // }
        long long res = 0;
        for(int i = 0; i < sorted.size(); i++) {
            int j = i;
            int k = sorted.size() - 1;
            
            while(j<=k) {
                int tmp = sorted[i].first + sorted[j].first + sorted[k].first;
                if(tmp == target) {
                    int plus = 0;
                    if(i==j && j==k ) {
                        if(sorted[i].second >= 3)
                            res += combination(sorted[i].second, 3);
                    } else if(i==j ) {
                        if(sorted[i].second >= 2) 
                            res += sorted[k].second * combination(sorted[i].second,2);
                    } else if(j==k ) {
                        if( sorted[j].second >= 2)
                            res += sorted[i].second * combination(sorted[j].second,2);
                    } else if(i==k) {
                        if(sorted[i].second >= 2)
                            res += sorted[j].second * combination(sorted[k].second,2);  
                    } else {
                         res += sorted[i].second*sorted[j].second*sorted[k].second;
                    }
                    res %= 1000000007; 
                    
                    k--;
                    j++;
                } else if (tmp > target) {
                    k--;
                } else {
                    j++;
                }
            }
            
            
        }
        
        return (int)res;
    }
};

//	870. Advantage Shuffle    

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<pair<int,int>> bidx;
        
        for(int i = 0; i < A.size(); i++) {
            // aidx.push_back(make_pair(A[i],i));
            bidx.push_back(make_pair(B[i],i));
        }

        // sort(aidx.begin(),aidx.end());
        sort(A.begin(),A.end());
        sort(bidx.begin(),bidx.end());
        
        
        vector<pair<int,int>> ridx; 
        vector<int> remain;
        
        
        int i,j = 0;
        while(i<A.size() && j<A.size()) {
            if(bidx[i].first >= A[j]) {
                remain.push_back(A[j++]);
            } else {
                ridx.push_back(make_pair(bidx[i++].second,A[j++]));
            }
        }
        
        
        vector<int> res(A.size(),-1);
        
        for(auto p: ridx) {
            res[p.first] = p.second;
        }
        
        j = 0;
        for(i = 0; i < res.size(); i++) {
            if(res[i] == -1) 
                res[i] = remain[j++];
        }
        
        return res;
        
    }
};

// 1423. Maximum Points You Can Obtain from Cards    

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int res = 0;
        int size = cardPoints.size();
        if(!cardPoints.size()) return 0;
        
        int sum = 0;
        for(auto i : cardPoints) {
            sum += i;
        }
        
        
        int tmp_sum = 0;
        for(int i = 0; i < size - k ; i++) {
            tmp_sum+=cardPoints[i];
        }
        
        int l = 0;
        int r = size - k - 1;
        int min_sum = tmp_sum;
        
        while(++l&&(++r < size)) {
            
            tmp_sum += cardPoints[r];
            tmp_sum -= cardPoints[l - 1];

            if(min_sum > tmp_sum) min_sum = tmp_sum;
        }
        
        
        
        return sum - min_sum;
    }
};

// 121. Best Time to Buy and Sell Stock


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int local_min = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            if(local_min > prices[i]) {
                local_min = prices[i];
            } else {
                if(max_profit < prices[i] - local_min)
                    max_profit = prices[i] - local_min;
            }
        }
        
        
        return max_profit;
    }
};

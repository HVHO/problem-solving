// 309. Best Time to Buy and Sell Stock with Cooldown

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        
        vector<int> buy(n,0);
        vector<int> sell(n,0);
        
        buy[0] = -prices[0];
        buy[1] = max(-prices[0],-prices[1]);
        sell[0] = 0;
        sell[1] = max(0,prices[1] - prices[0]);
        
        for(int i = 2; i < n; i++) {
            buy[i] = max(sell[i-2] - prices[i], buy[i-1]);
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
        }

        return sell[n-1];
    }
};

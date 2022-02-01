// 121. Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int mn = prices[0];

        for(int i = 1; i < prices.size(); i++) {
            mn = min(mn,prices[i]);
            res = max(res,prices[i]-mn);
        }
        return res;
    }
};

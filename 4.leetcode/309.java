// 309. Best Time to Buy and Sell Stock with Cooldown

class Solution {
    
    public int maxProfit(int[] prices) {
        int len = prices.length;
        if(len == 0) return 0;
        int[] buy = new int[len];
        int[] sell = new int[len];
        int[] cooldown = new int[len];
        
        buy[0] = -prices[0];
        sell[0] = Integer.MIN_VALUE + 10000;
        cooldown[0] = 0;
        
        for(int i = 1; i < len; i++) {
            buy[i] = Math.max(cooldown[i - 1], buy[i - 1] + prices[i - 1]) - prices[i];
            sell[i] = Math.max(sell[i - 1] - prices[i - 1], buy[i - 1]) + prices[i];
            cooldown[i] = Math.max(sell[i - 1], Math.max(cooldown[i - 1], buy[i - 1]));    
        }
        
        
        return Math.max(sell[len - 1],cooldown[len - 1]);
        
        
    }
}
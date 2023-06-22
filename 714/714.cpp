class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() == 0) return 0;
        int buy = -prices[0];
        int sell = 0;
        for(int i = 1 ; i < prices.size(); i++)
        {
            buy = max(buy, sell - prices[i]);
            sell = max(sell, prices[i] + buy - fee);
        }
        return max(sell,0);
    }
};
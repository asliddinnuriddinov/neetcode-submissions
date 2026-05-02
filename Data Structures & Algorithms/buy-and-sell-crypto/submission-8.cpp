class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int maxProfit = 0;

        for(int sell = 1; sell < prices.size(); sell++){
            maxProfit = max(maxProfit, prices[sell] - buy);
            buy = min(buy, prices[sell]);
        }
        return maxProfit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int result = 0;
        for(int sell = 1; sell < prices.size(); sell++){
            result = max(result, prices[sell] - buy);
            buy = min(buy, prices[sell]);
        }
        return result;
    }
};

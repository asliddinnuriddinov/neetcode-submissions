class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int max = 0;

        for(int sell = 0; sell < prices.size(); sell++){
            if(prices[sell] - buy > max) max = prices[sell] - buy;

            if(prices[sell] < buy) buy = prices[sell];
        }

        return max;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int maxProfit = 0;

        for(int i = 0; i < prices.size(); i++){
            int profit = prices[i] - buy;
            if(profit > maxProfit) maxProfit = profit;

            else if(profit <= 0){
                buy = prices[i];
            }
        }
        return maxProfit;
    }
};

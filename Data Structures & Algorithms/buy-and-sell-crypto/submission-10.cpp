class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int res = 0;

        for(int &sell : prices){
            res = max(res, sell - buy);
            buy = min(buy, sell);
        }
        return res;
    }
};

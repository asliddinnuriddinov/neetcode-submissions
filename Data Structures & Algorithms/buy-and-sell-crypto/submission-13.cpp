class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int res = 0;
        for(int &sell : prices){
            buy = min(buy, sell);
            res = max(res, sell - buy);
        }
        return res;
    }
};

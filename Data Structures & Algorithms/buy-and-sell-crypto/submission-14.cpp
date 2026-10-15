class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, sell = prices[0];
        for(int &buy : prices){
            sell = min(sell, buy);
            res = max(res, buy - sell);
        }
        return res;
    }
};

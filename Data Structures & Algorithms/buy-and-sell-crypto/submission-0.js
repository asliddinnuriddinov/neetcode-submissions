class Solution {
    /**
     * @param {number[]} prices
     * @return {number}
     */
    maxProfit(prices) {
        let buy = prices[0]
        let res = 0

        for( let i = 1; i<prices.length; i++ ){
            if( prices[i] - buy > res ){
                res = prices[i] - buy
            }
            
            if( prices[i] < buy ){
                buy = prices[i]
            }
        }

        return res
    }
}

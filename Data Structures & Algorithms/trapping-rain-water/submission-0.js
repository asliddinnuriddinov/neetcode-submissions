class Solution {
    /**
     * @param {number[]} height
     * @return {number}
     */
    trap(heights) {
        let result = 0
        let leftMax = 0
        let pre = []

        let rightMax = 0
        let suf = []

        for( let i = 0; i < heights.length; i++ ){
            if( i == 0 ){
                leftMax = Math.max( leftMax, heights[0] )
                pre.push(0)
            }else{
                pre.push(leftMax)
                leftMax = Math.max( leftMax, heights[i] )
            }
        }

        for( let i = heights.length-1; i>=0; i-- ){
            if( i == heights.length-1 ){
                rightMax = Math.max( rightMax, heights[heights.length-1] )
                suf.unshift(0)
            }else{
                suf.unshift(rightMax)
                rightMax = Math.max( rightMax, heights[i] )
            }
        }

        for( let i = 0; i < heights.length; i++ ){
            let curSum = Math.min( pre[i], suf[i] ) - heights[i]
            if( curSum > 0 ){
                result+=curSum
            }
        }

        return result
    }
}

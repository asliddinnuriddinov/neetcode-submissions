class Solution {
    /**
     * @param {number[]} heights
     * @return {number}
     */
    largestRectangleArea(heights) {
        let h = heights
        let max = 0
        let stack = [ {index:0, height: h[0]} ]

        for(let i=1; i < h.length; i++){
            let start = i
            while(h[i] < stack[stack.length-1]?.height){
                const item=stack.pop()
                max = Math.max(max, item.height * (i - item.index) )
                start=item.index
            }
            stack.push({index:start, height:h[i]})
        }
        for(let i=0; i<stack.length; i++){
            max = Math.max( max, stack[i].height * (h.length-stack[i].index) )
        }
        return max
    }
}

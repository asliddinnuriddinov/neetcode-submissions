class Solution {
    /**
     * @param {number[]} heights
     * @return {number}
     */
    maxArea(heights) {
        let max = 0
        let start = 0
        let end = heights.length-1

        while(start<end){
            if( (end-start) * Math.min(heights[start],heights[end]) > max ){
                max = (end-start) * Math.min(heights[start],heights[end])
            }
            if(heights[end]<heights[start]){
                end--
            }else if(heights[start]<heights[end]){
                start++
            }else{
                start++
            }
        }
        return max
    }
}

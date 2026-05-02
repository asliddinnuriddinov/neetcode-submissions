class Solution {
    /**
     * @param {number[]} temperatures
     * @return {number[]}
     */
    dailyTemperatures(arr) {
        const res = new Array(arr.length).fill(0)
        let stack=[
            {
                val: arr[0],
                ind: 0   
            }
        ]

        for(let i=1; i<arr.length; i++){
            if( arr[i] <= stack[stack.length-1]?.val ){
                stack.push({
                    val: arr[i],
                    ind: i
                })
            }else{
                while( arr[i] > stack[stack.length-1]?.val && stack.length>0 ){
                    res[stack[stack.length-1]?.ind] = i - stack[stack.length-1]?.ind
                    stack.pop()
                }
                stack.push({
                    val: arr[i],
                    ind: i
                })
            }
        }

        return res
    }
}

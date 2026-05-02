class Solution {
    /**
     * @param {number[]} temperatures
     * @return {number[]}
     */
    dailyTemperatures(temperatures) {
        const stack = []
        const res = Array.from( {length:temperatures.length}, () => 0 )
        
        for( let i=0; i<temperatures.length; i++ ){
            if( stack.length==0 || stack[stack.length-1]?.val > temperatures[i] ){
                const data = { val:temperatures[i], ind:i }
                stack.push(data)
            }else{
                while( stack[stack.length-1]?.val < temperatures[i] ){
                    const index = stack[stack.length-1].ind
                    res[index] = i - index
                    stack.pop()
                }
                const data = { val:temperatures[i], ind:i }
                stack.push(data)
            }
        }
        return res
    }
}

class Solution {
    /**
     * @param {string[]} tokens
     * @return {number}
     */
    evalRPN(tokens) {
        const stack=[]
        const operations=['+','-','*','/']
        for(const i of tokens){
            if(!operations.includes(i)){
                stack.push(i)
            }
            else{
                const result=eval(`${stack[stack.length-2]} ${i} ${stack[stack.length-1]}`)
                stack.pop()
                stack.pop()
                stack.push(parseInt(result))
            }
        }
        return stack[0]
    }
}

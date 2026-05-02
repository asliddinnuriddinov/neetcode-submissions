class Solution {
    /**
     * @param {string[]} tokens
     * @return {number}
     */
    evalRPN(tokens) {
        const stack=[]
        const operators="+-*/"

        for(let i=0; i<tokens.length; i++){
            if( !operators.includes(tokens[i]) ){
                stack.push(tokens[i])
            }else{
                const n = stack.length
                const res = parseInt(eval(` ${stack[n-2]} ${tokens[i]} ${stack[n-1]} `))
                stack.pop()
                stack.pop()
                stack.push(res)
            }
        }
        return stack[0]
    }
}

class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isValid(s) {
        const opens="({["
        const closes=")}]"
        const stack=[]

        for(let i=0; i<s.length; i++){
            if( opens.includes(s[i]) ){
                stack.push(s[i])
            }else{
                if(stack.length==0){
                    console.log(1)
                    return false
                }
                if( opens.indexOf(stack[stack.length-1]) != closes.indexOf(s[i]) ){
                    console.log(2)
                    return false
                }else{
                    stack.pop()
                }
            }
        }
        return stack.length==0
    }
}

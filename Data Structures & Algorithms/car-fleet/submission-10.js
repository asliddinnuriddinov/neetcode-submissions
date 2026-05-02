class Solution {
    /**
     * @param {number} target
     * @param {number[]} position
     * @param {number[]} speed
     * @return {number}
     */
    carFleet(target, position, speed) {
        let sorted = position.map( (x,i) => {
            const data ={
                pos: x,
                speed: speed[i]
            }
            return data
        })
        sorted=sorted.sort((a,b)=>b.pos-a.pos)
        const stack=[]
        for( let i=0; i<sorted.length; i++ ){
            if( stack.length != 0 ){
                const n = stack.length
                const current = (target-sorted[i].pos) / sorted[i].speed
                const stackTime=(target-stack[n-1].pos) / stack[n-1].speed
                if( stackTime >= current ){
                    continue
                }else{
                    stack.push(sorted[i])
                }
            }else{
                stack.push( sorted[i] )
            }
        }
        console.log(stack)
        return stack.length
    }
}

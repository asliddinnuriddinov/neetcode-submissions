class Solution {
    /**
     * @param {number} target
     * @param {number[]} position
     * @param {number[]} speed
     * @return {number}
     */
    carFleet(target, position, speed) {
        let sorted=position.map((item, ind) => {
            const obj = {
                pos : item,
                t : (target-item)/speed[ind]
            }
            return obj
        })
        sorted=sorted.sort((a,b) => a.pos - b.pos)

        let stack=[sorted[sorted.length-1]]

        for(let i=sorted.length-2; i>=0; i--){
            if( sorted[i].t <= stack[stack.length-1].t ){
                continue
            }else{
                stack.push(sorted[i])
            }
        }
        return stack.length || 0
    }
}

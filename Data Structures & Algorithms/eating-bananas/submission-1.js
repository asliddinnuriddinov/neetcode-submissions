class Solution {
    /**
     * @param {number[]} piles
     * @param {number} h
     * @return {number}
     */
    minEatingSpeed(piles, h) {
        let res = Infinity
        let L = 0
        let R = Math.max(...piles)

        while( L <= R ){
            let mid = Math.floor( ( L + R ) / 2 )
            let sum = 0
            for(let i = 0; i < piles.length; i++){
                let hours = Math.ceil( piles[i] / mid )
                sum = sum + hours
            }
            if( sum <= h && mid < res ){
                res = mid
                R = mid - 1
            }
            if( sum > h ){
                L = mid + 1
            }
        }

        return res
    }
}

class Solution {
    /**
     * @param {number[]} nums
     * @param {number} k
     * @return {number[]}
     */
    topKFrequent(nums, k) {
        const hash = {}
        let max = 0
        let res = []
        for( let i = 0; i < nums.length; i++ ){
            hash[ nums[i] ] = 1 + ( hash[ nums[i] ] ?? 0 )
            if( hash[ nums[i] ] > max ) max = hash[ nums[i] ]
        }
        const bucket = Array.from( { length: max }, () => [] )
        console.log(bucket,hash)
        for( let c in hash ){
            bucket[ hash[c] - 1 ].push(c)
            console.log(bucket)
        }
        for( let i = bucket.length - 1; i >= 0; i-- ){
            if( res.length == k ) break
            for( let j = 0; j < bucket[i].length; j++ ){
                if( res.length == k ) break
                res.push( bucket[i][j] )
            }
        }
        return res
    }
}

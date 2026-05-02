class Solution {
    /**
     * @param {string} s
     * @param {number} k
     * @return {number}
     */
    characterReplacement(s, k) {
        let res = 0
        let hash = {}
        let l = 0

        for( let r = 0; r < s.length; r++ ){
            let currMax = 0
            hash[s[r]] = ( hash[[s[r]]] ?? 0 ) + 1
            for( let c in hash ){
                if( hash[c] > currMax ) currMax = hash[c]
            }
            if( (r - l + 1) - currMax <= k ){
                if( r - l + 1 > res ) res = r - l + 1
            }else{
                hash[ s[l] ] = hash[ s[l] ] - 1
                l+=1
            }
        }
        return res
    }
}

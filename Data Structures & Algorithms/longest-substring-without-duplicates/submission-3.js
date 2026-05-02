class Solution {
    /**
     * @param {string} s
     * @return {number}
     */
    lengthOfLongestSubstring(s) {
        let set = new Set()
        let max = 0;
        let l = 0;

        for( let i = 0; i < s.length; i++ ){
            while( set.has( s[i] ) ){
                set.delete( s[l] )
                l++
            }
            set.add( s[i] )
            max = Math.max( max, i - l + 1 )
        }

        return max
    }
}

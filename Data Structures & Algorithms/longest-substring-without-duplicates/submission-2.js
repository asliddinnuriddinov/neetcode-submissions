class Solution {
    /**
     * @param {string} s
     * @return {number}
     */
    lengthOfLongestSubstring(s) {
        let current = [s[0]]
        let max = 0;

        for( let i = 1; i < s.length; i++ ){
            if( !current.includes( s[i] ) ){
                current.push( s[i] )
            }else{
                while( current.includes( s[i] ) ){
                    current.shift()
                }
                current.push( s[i] )
            }
            
            if( current.length > max ) max = current.length
        }

        return s.length == 1 ? 1 : max
    }
}

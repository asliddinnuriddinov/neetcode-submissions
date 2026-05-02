class Solution {
    /**
     * @param {string} s
     * @param {string} t
     * @return {boolean}
     */
    isAnagram(s, t) {
        if( s.length != t.length ) return false
        const hashS = {}, hashT={};
        for( let i=0; i<s.length; i++ ){
            hashS[ s[i] ] = 1 + ( hashS[ s[i] ] ?? 0 )
            hashT[ t[i] ] = 1 + ( hashT[ t[i] ] ?? 0 )
        }
        console.log(hashS,hashT)
        for( let c in hashS ){
            if( hashS[c] != hashT[c] ){
                console.log(hashS[c], hashT[c], c)
                return false
            }
        }
        return true
    }
}

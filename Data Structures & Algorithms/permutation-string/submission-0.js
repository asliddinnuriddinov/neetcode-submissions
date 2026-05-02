class Solution {
    /**
     * @param {string} s1
     * @param {string} s2
     * @return {boolean}
     */
    checkInclusion(s1, s2) {
        let obj1={}, obj2={};
        let l = 0

        for( let c in s1.split("") ){
            obj1[s1[c]] = ( obj1[s1[c]] ?? 0 ) + 1
        }

        for( let c in s2.split("").slice(0, s1.length) ){
            obj2[s2[c]] = ( obj2[s2[c]] ?? 0 ) + 1
        }

        for( let i = s1.length - 1; i < s2.length; i++  ){
            let flag = true
            for( let c in obj2 ){
                if( obj2[c] <= 0 ) continue
                if( !obj1.hasOwnProperty(c) || obj1[c] != obj2[c] ){
                    obj2[s2[l]] = obj2[s2[l]] - 1
                    l++
                    if (s2[i + 1]) {
                        obj2[s2[i+1]] = (obj2[s2[i+1]] ?? 0) + 1;
                    }
                    flag = false
                    break
                }
            }
            if( flag ){
                return true
            }
        }
        return false
    }
}

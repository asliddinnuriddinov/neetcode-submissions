class Solution {
    /**
     * @param {string} s
     * @param {string} t
     * @return {boolean}
     */
    isAnagram(s, t) {
        if(s.length !== t.length) return false
        const arr = Array.from({length: 26}, ()=> 0)

        for(let i = 0; i < s.length; i++){
            const posS = s.charCodeAt(i) - 97
            const posT = t.charCodeAt(i) - 97

            arr[posS] = arr[posS] + 1
            arr[posT] = arr[posT] - 1
        }

        for(const count of arr){
            if(count<0 || count>0) return false
        }
        return true
    }
}

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
            const pos = s.charCodeAt(i) - 97

            arr[pos] = arr[pos] + 1
        }
        for(let i = 0; i < s.length; i++){
            const pos = t.charCodeAt(i) - 97

            arr[pos] = arr[pos] - 1
        }

        for(const count of arr){
            if(count<0 || count>0) return false
        }
        return true
    }
}

class Solution {
    /**
     * @param {string[]} strs
     * @returns {string}
     */
    encode(strs) {
        console.log(strs.map(str => `${str.length}#` + str).join(''))
        return strs.map(str => `${str.length}#` + str).join('')
    }

    /**
     * @param {string} str
     * @returns {string[]}
     */
    decode(str) {
        if(str.length === 0) return []
        let result = []
        let i = 0
        while(i < str.length){
            let j = i
            while(str[j] !== '#'){
                j++
            }
            const count = parseInt(str.slice(i, j))
            result.push(str.slice(j + 1, count + 1 + j))
            i = count + 1 + j
        }
        return result
    }
}

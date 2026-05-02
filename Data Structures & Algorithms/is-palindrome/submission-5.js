class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isPalindrome(s) {
        s=s.split('').map(x=>this.isAlphabetical(x)?x.toLowerCase():'').join('')
        let start=0
        let end=s.length-1
        while(start < end){
            if(s[start] != s[end]){
                return false
            }
            start++
            end--
        }
        return true
    }
    isAlphabetical(str) {
        return /^[a-zA-Z0-9]+$/.test(str);
    }
}


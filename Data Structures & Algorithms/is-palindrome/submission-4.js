class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isPalindrome(s) {
        let start=0
        let end=s.length-1
        while(start < end){
            while(!this.isAlphabetical(s[start]) && start<end){
                start++
            }
            while(!this.isAlphabetical(s[end]) && start<end){
                end--
            }
            if(s[start]?.toLowerCase() != s[end]?.toLowerCase()){
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

class Solution {
    /**
     * @param {string} s
     * @param {string} t
     * @return {boolean}
     */
    isAnagram(s, t) {
        if(s.length!=t.length) return false
        let countS={},countT={}
        for(let i=0;i<s.length;i++){
            if(s[i] in countS){
                countS[s[i]]=countS[s[i]]+1
            }
            else{
                countS[s[i]]=1
            }
            if(t[i] in countT){
                countT[t[i]]=countT[t[i]]+1
            }
            else{
                countT[t[i]]=1
            }
        }
        for(let x in countS){
            if(countS[x]!=countT[x]) return false
        }
        return true
    }
}

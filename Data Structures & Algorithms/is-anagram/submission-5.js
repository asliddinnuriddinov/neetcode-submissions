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
            countS[s[i]]=1+(countS[s[i]]??0)
            countT[t[i]]=1+(countT[t[i]]??0)
        }
        for(let x in countS){
            if(countS[x]!=countT[x]) return false
        }
        return true
    }
}

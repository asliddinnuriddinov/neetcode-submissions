class Solution {
    /**
     * @param {string[]} strs
     * @return {string[][]}
     */
    groupAnagrams(strs) {
        const map = new Map()

        for(const str of strs){
            const arr = Array.from({length: 26}, ()=> 0)
            for(const s of str){
                const pos = s.charCodeAt(0) - 97
                arr[pos] = (arr[pos] ?? 0) + 1
            }
            const key = arr.join('#')
            if(map.has(key)){
                map.set(key, [...map.get(key), str])
            }else{
                map.set(key, [str])
            }
        }

        return Array.from(map.values())
    }
}

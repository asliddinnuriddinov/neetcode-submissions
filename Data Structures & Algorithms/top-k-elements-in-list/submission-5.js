class Solution {
    /**
     * @param {number[]} nums
     * @param {number} k
     * @return {number[]}
     */
    topKFrequent(nums, k) {
        const hash = new Map()
        const bucket = Array.from({length: nums.length + 1}, () => [])

        for(let i = 0; i < nums.length; i++){
            hash.set(nums[i], (hash.get(nums[i]) ?? 0) + 1)
        }

        for(const [key, value] of hash.entries()){
            bucket[value].push(key)
        }
        const result = []
        for(let r = bucket.length - 1; r >= 0; r--){
            if(bucket[r].length === 0) continue
            for(let n = bucket[r].length - 1; n >= 0; n--){
                result?.push(bucket[r][n])
                if(result.length === k) return result
            }
        }
        return result
    }
}

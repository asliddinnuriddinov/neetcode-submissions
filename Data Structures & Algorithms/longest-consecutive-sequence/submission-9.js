class Solution {
    /**
     * @param {number[]} nums
     * @return {number}
     */
    longestConsecutive(nums) {
        const set = new Set(nums)
        let res = 0

        for( let i=0; i<nums.length; i++ ){
            if( set.has( nums[i] - 1 ) ) continue
            let greater = nums[i] + 1
            let currentMax = 0
            while( set.has(greater) ){
                currentMax+=1
                greater+=1
            }
            if(currentMax>=res) res=currentMax+1
        }
        return res
    }
}

class Solution {
    /**
     * @param {number[]} nums
     * @return {boolean}
     */
    hasDuplicate(nums) {
        let hash={}
        for(let i=0;i<nums.length;i++){
            if(nums[i] in hash) return true
            hash[nums[i]]=nums[i]
        }
        return false
    }
}

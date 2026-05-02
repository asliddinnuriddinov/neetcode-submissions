class Solution {
    /**
     * @param {number[]} nums
     * @return {boolean}
     */
    hasDuplicate(nums) {
        const hash={}

        for(let i=0; i<nums.length; i++){
            if(nums[i] in hash){
                return true
            }else{
                hash[nums[i]] = 1
            }
        }
        return false
    }
}

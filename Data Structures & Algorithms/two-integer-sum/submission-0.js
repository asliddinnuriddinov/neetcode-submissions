class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number[]}
     */
    twoSum(nums, target) {
        let map={}
        for(let i=0;i<nums.length;i++){
            let diff=target-nums[i]
            if(!(diff in map)){
                map[nums[i]]=i
                continue
            }
            return [map[diff],i]
        }
    }
}

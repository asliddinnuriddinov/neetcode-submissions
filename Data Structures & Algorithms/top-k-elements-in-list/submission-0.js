class Solution {
    /**
     * @param {number[]} nums
     * @param {number} k
     * @return {number[]}
     */
    topKFrequent(nums, k) {
        let hash={}
        for(let i=0; i<nums.length; i++){
            if(nums[i] in hash){
                hash[nums[i]]=hash[nums[i]]+1
            }else{
                hash[nums[i]]=1
            }
        }
        nums = [... new Set(nums)].sort((a,b)=>hash[b]-hash[a])
        return nums.slice(0,k)
    }
}

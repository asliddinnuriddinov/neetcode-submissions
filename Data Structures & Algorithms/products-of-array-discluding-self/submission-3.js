class Solution {
    /**
     * @param {number[]} nums
     * @return {number[]}
     */
    productExceptSelf(nums) {
        const pre = [1]
        const suf = []
        suf[nums.length-1]=1
        const res=[]
        for(let i=1; i<nums.length; i++){
            pre[i] = nums[i - 1] * pre[i - 1]
        }
        for(let i=nums.length-2; i>=0; i--){
            suf[i] = suf[i + 1] * nums[i + 1]
        }
        for(let i=0; i<pre.length; i++){
            res[i] = pre[i] * suf[i]
        }
        return res
    }
}

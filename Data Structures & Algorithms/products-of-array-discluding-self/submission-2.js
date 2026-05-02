class Solution {
    /**
     * @param {number[]} nums
     * @return {number[]}
     */
    productExceptSelf(nums) {
        let pre=[nums[0]]
        let suf=[]
        let res=[]
        suf[nums.length-1]=nums[nums.length-1]

        for(let i=1; i<nums.length; i++){
            pre.push(pre[i-1]*nums[i])
        }

        for(let i=nums.length-2; i>=0; i--){
            suf[i]=suf[i+1]*nums[i]
        }

        for(let i=0; i<nums.length; i++){
            if(i==0){
                res.push(suf[i+1])
                continue
            }
            if(i==nums.length-1){
                res.push(pre[i-1])
                continue
            }
            res.push(pre[i-1]*suf[i+1])
        }
        return res
    }
}

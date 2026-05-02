class Solution {
    /**
     * @param {number[]} nums
     * @return {number[][]}
     */
    threeSum(nums) {
        nums=nums.sort((a,b)=>a-b)
        let res=[]
        for(let i=0; i<nums.length; i++){
            if(i>0&&nums[i]===nums[i-1]) continue
            let s = i+1
            let e = nums.length-1
            let target = -1 * nums[i]
            while(s<e && i!=s && i!=e){
                const curSum = nums[s] + nums[e]
                if( curSum >target ){
                    e--
                }else if( curSum < target ){
                    s++
                }else{
                    const newTriplet=[nums[i],nums[s],nums[e]]
                    if(!res.includes(newTriplet)){
                        res.push(newTriplet)
                    }
                    s++
                    e--
                    while(s<e&&nums[s]===nums[s-1]){
                        s++
                    }
                }
            }
        }
        return res
    }
}

class Solution {
    /**
     * @param {number[]} nums
     * @return {number}
     */
    findMin(nums) {
        let res = Infinity
        let L = 0
        let R = nums.length-1

        while( L <= R ){
            let mid = Math.floor( ( R + L ) / 2 )
            if( nums[mid] < res ) res = nums[mid]
            if( nums[mid] > nums[R] ){
                L = mid + 1
            }else{
                R = mid - 1
            }
        }

        return res
    }
}

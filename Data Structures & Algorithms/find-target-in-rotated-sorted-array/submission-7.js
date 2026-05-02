class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number}
     */
    search(nums, target) {
        let L = 0
        let R = nums.length-1

        while( L <= R ){
            let mid = Math.floor( ( L + R ) / 2 )

            if( nums[mid] === target ) return mid

            if( nums[L] <= nums[mid] ){
                if( target <= nums[mid] && nums[L] <= target ){
                    R = mid - 1
                }else{
                    L = mid + 1
                }
            }else{
                if( nums[R] >= target && nums[mid] <= target ){
                    L = mid + 1
                }else{
                    R = mid - 1
                }
            }
        }

        return -1
    }
}
